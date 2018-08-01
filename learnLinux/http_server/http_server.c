#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <signal.h>

#define SIZE (1024*4)
typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;

typedef struct FocusField
{
    char output[SIZE];
    char* method;
    char* url;
    char* url_path;
    char* quary_string;
    int content_length;
}FocusField;

int ReadLine(int sock,char buf[],size_t max_size)
{
    //按行从socket中读取数据
    //存在的换行：1.\n 2.\r 3.\n\r
    //从sock中读取字符,一次读一个
    char c = '\0';
    size_t index = 0;
    while(index < max_size)
    {
        ssize_t read_size = recv(sock,&c,1,0);
        if(read_size <= 0)
        {
            //小于0说明读到了错误
            //等于0 说明读完了但是却没有遇到换行符，那么一定就是出错了
            return -1;
        }
        if(c == '\r')
        {
            //如果当前字符是\r 
                //再接着都第二个字符,如果第二个字符是\n,就直接忽略掉\r
                //如果第二个字符不是\n,就把\r修改为\n
            recv(sock,&c,1,MSG_PEEK);
            if(c == '\n')
            {
                recv(sock,&c,1,0);
            }
            else
            {
                //\r  --->  \n
                c = '\n';
            }
        }
        buf[index++] = c;
        //如果当前字符是\n
        if(c == '\n')
        {
            break;
        }
    }
    buf[index] = '\0';
    return 0;
}


int strtok_first(char first_line[],const char* split,char* res[],int size)
{
    char* p = NULL;
    int index = 0;
    char* tmp = NULL;
    p = strtok_r(first_line,split,&tmp);
    while(p)
    {
        if(index > size)
        {
            return index;
        }
        res[index++] = p;
        p = strtok_r(NULL,split,&tmp);
    }
    return index;
}

int parse_first(char first_line[],char** method,char** url)
{
    //http首行：方法 + url + 版本号 (先不进行处理)
    //把首行按照以空格进行分割
    char* res[5];
    int size = strtok_first(first_line," ",res,5);  //最后一个元素表示res中的元素的个数
    if(size != 3)
    {
        printf("strtok_first failed.\n");
        return -1;
    }
    *method = res[0];
    *url = res[1];
    return 0;
}

//将url切分为url_path + quary_string
int parse_quary(char* url,char** url_path,char** quary_string)
{
    //url：1./index/html？a&b=10...
    //     2.http://www.baidu.com/index/html....（先不处理）
    char* p = url;
    *url_path = url;
    for(;*p != '\0';++p)
    {
        if(*p == '?')
        {
            *p = '\0';
            *quary_string = p + 1;
            return 0;
        }
    }
    return 0;
}

int Header(int sock,int* length)
{
    while(1)
    {
        char buf[SIZE] = {0};
        ssize_t read_size = ReadLine(sock,buf,sizeof(buf));
        if(read_size < 0)
        {
            //读失败
            return -1;
        }
        //if(read_size == 0)    //发现不能等于0
        //{
        //    //读完了，还没有读到'\n'，说明也出错了
        //    return -1;
        //}
        if(strcmp(buf,"\n") == 0)
        {
            return 0;
        }
        //进行判断Content-Length
        const char* con = "Content-Length: ";
        if(length != NULL && strncmp(buf,con,strlen(con)) == 0)
        {
            *length = atoi(buf + strlen(con));
            //在这儿，找到了长度并不能立即返回。要将header中所有的数据都读出来。（注意粘包问题）
        }
    }
    return 0;
}


int Is_Dir(const char* file_path)
{
    struct stat s;
    int ret = stat(file_path,&s);
    if(ret < 0)
    {
        return 0;
    }
    if(S_ISDIR(s.st_mode))
    {
        return 1;
    }
    return 0;
}

void file_path(const char* url_path,char* file_path)
{
    sprintf(file_path,"./root%s",url_path);
    //填充目录
    //如果是根目录：/ ====》/index.html
    if(file_path[strlen(file_path) - 1] == '/')
    {
        strcat(file_path,"main.html");
    }
    else if(Is_Dir(file_path))
    {
        //判断是否是目录
        strcat(file_path,"/index.html");
    }
}

int GetFileSize(const char* file)
{
    struct stat s;
    int ret = stat(file,&s);
    if(ret < 0)
    {
        return 0;
    }
    return s.st_size;
}

void Handler404(int sock)
{
    //处理错误：要进行报文响应的错误回复
    const char* first_line = "HTTP/1.1 404 Not Found\n";
    const char* black_line = "\n";
    const char* body = "<head><meta http-equiv=\"content-type\" content=\"text/html;charset=utf-8\"></head>"
                        "<h1>oh,no!!访问出错啦</h1>";
    send(sock,first_line,strlen(first_line),0);
    send(sock,black_line,strlen(black_line),0);
    send(sock,body,strlen(body),0);
}

int ResponseStaticFile(int sock,char* file_path)
{
    int fd = open(file_path,O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        return 404;
    }
    //构造http的响应报文头
    const char* file_line = "HTTP/1.1 200 OK\n";
    send(sock,file_line,strlen(file_line),0);
    //header:不处理，浏览器可以自动获取
    const char* black_line = "\n";
    send(sock,black_line,strlen(black_line),0);
    //处理body部分，即从file_path的文件中读出来，再写回到sock之中
    
    //ssize_t size = GetFileSize(file_path);
    //int i = 0;
    //char c = '\0';
    //for(i = 0;i < size;++i)
    //{
    //    read(fd,&c,1);
    //    send(sock,&c,1,0);
    //}
    sendfile(sock,fd,NULL,GetFileSize(file_path));
    close(fd);
    return 200;
}

//处理静态页面
int StaticFile(int sock,FocusField* focu)
{
    char file[SIZE] = {0};
    //找到静态页面的路径，并写到file_path之中
    file_path(focu->url_path,file);
    //2.就是服务器对于静态页面的响应了。
    int ret = ResponseStaticFile(sock,file);
    return ret;
}

//父进程：要做的事：
//1.将body或者quary_string写进管道之中
//2.子进程完成程序替换之后，将管道之中的数据读出来再写回到相应之中。
int FatherHeadlerDynamicPage(int sock,FocusField* focu,int father_write,int father_read)
{
   if(strcasecmp(focu->method,"POST") == 0)
   {
     int i = 0;
     char c = '\0';
     for(i = 0;i < focu->content_length;++i)
     {
       read(sock,&c,1);
       write(father_write,&c,1);
     }
   }
   //构造HTTP响应
   const char* first_line = "HTTP/1.1 200 OK\n";
   send(sock,first_line,strlen(first_line),0);
   const char* black_line = "\n";
   send(sock,black_line,strlen(black_line),0);
   //循环的从管道之中读取
   char r = '\0';
   while(read(father_read,&r,1))
   {
      send(sock,&r,1,0);
   }
   //可以使用信号忽略子进程，也可以使用wait/waitpid去等待子进程
   return 200;
}

//子进程要做的事：
//1.设置相关的环境变量
//2.把标准输出，标准输入重定向到管道之中
//3.进行程序替换
int SonHeadlerDynamicPage(FocusField* focu,int son_read,int son_write)
{
    char method_env[SIZE] = {0}; 
    sprintf(method_env,"REQUEST_METHOD=%s",focu->method);
    putenv(method_env);
    //要进行判断是GET/POST方法
    if(strcasecmp(focu->method,"GET") == 0)
    {
      char quary_env[SIZE] = {0};
      sprintf(quary_env,"QUERY_STRING=%s",focu->quary_string);
      putenv(quary_env);
    }
    else
    {
      char content_env[SIZE] = {0};
      sprintf(content_env,"CONTENT_LENGTH=%d",focu->content_length);
      putenv(content_env);
    }
    //把标准输入重定向到管道的读端
    dup2(son_read,0);
    //把标准输出重定向到管道的写端
    dup2(son_write,1);

    char path[SIZE] = {0};
    file_path(focu->url_path,path); 
    if(execl(path,path,NULL) < 0)
    {
      exit(1);
    }
    return 200;
}

int HanderDynamicPage(int sock,FocusField* focu)
{
    int ret = 200;
    //1.创建一对匿名管道
    int fd1[2],fd2[2];
    if(pipe(fd1) < 0)
    {
      ret = 404;
      perror("pipe");
      return ret;
    }
    if(pipe(fd2) < 0)
    {
      close(fd1[0]);
      close(fd1[1]);
      ret = 404;
      perror("pipe");
      return ret;
    }
    int father_read = fd1[0];
    int son_write = fd1[1];
    int son_read = fd2[0];
    int father_write = fd2[1];

    //2.创建子进程
    int fork_ret = fork(); 
    if(fork_ret < 0)
    {
      ret = 404;
      perror("fork");
      goto END;
    }
    else if(fork_ret > 0)
    {
      //父进程
      close(son_read);
      close(son_write);
      ret = FatherHeadlerDynamicPage(sock,focu,father_write,father_read);
    }
    else
    {
      //子进程
      close(father_read);
      close(father_write);
      ret = SonHeadlerDynamicPage(focu,son_read,son_write);
    }

    close(fd1[0]);
    close(fd1[1]);
    close(fd2[0]);
    close(fd2[1]);
END:
    if(ret != 200)
    {
      return 404;
    }
    return ret;
}

void HandlerProcess(int sock)
{
    int err_code = 200;
    //1.解析请求
    //a)读取首行并解析
    FocusField focu;
    //初始化结构体
    memset(&focu,0,sizeof(focu));
    //错误处理
    //对于错误的情况，统一返回404(1.封装函数2.goto语句-->一般不要往前跳)
    if(ReadLine(sock,focu.output,(sizeof(focu.output) - 1)) < 0)
    {
        err_code = 404;
        goto END;
        //构造404响应的代码
    }
    //若读取成功,则打印处理
    printf("first_line:%s\n",focu.output);
    //b)解析method,URL
    if(parse_first(focu.output,&focu.method,&focu.url) < 0)
    {
        err_code = 404;
        goto END;
        //错误处理
    }
    //c)根据URL解析quary 与url_path
    if(parse_quary(focu.url,&focu.url_path,&focu.quary_string) < 0)
    {
        err_code = 404;
        goto END;
        //错误处理
    }
    if(Header(sock,&focu.content_length))
    {
        printf("handler failed.\n");
        err_code = 404;
        goto END;
    }
    //2.根据解析计算响应并回复
    if(strcasecmp(focu.method,"GET") == 0 && focu.quary_string == NULL)
    {
        //a)处理静态页面(其实就是一个HTML的文件),不包含quary_string的请求就是静态请求
        err_code = StaticFile(sock,&focu);
    }
    else if(strcasecmp(focu.method,"GET") == 0 && focu.quary_string != NULL)
    {
        //b)处理动态页面,采用CGI(通用网关接口)技术,
        //包含quary_string的GET方法
        err_code = HanderDynamicPage(sock,&focu);
    }
    else if(strcasecmp(focu.method,"POST") == 0)
    {
        //b)处理动态页面,采用CGI(通用网关接口)技术,
        //POST请求的都属于动态页面
        err_code = HanderDynamicPage(sock,&focu);
    }
    else
    {
        printf("method is not support! method = %s\n",focu.method);
        err_code = 404;
        goto END;
    }
END:
    if(err_code != 200)
    {
        Handler404(sock);
    }
    //在这儿，只考虑短连接，每次客户端过来都要进行连接。
    //此处由于是服务器主动断开连接，就会进入close_wait（）状态。
    //若大量的请求断开处理，就会存在服务器可能会连接不上。进行重用连接处理：
    close(sock);
}

void* PthreadEntry(void* arg)
{
    int64_t sock = (int64_t)arg;
    HandlerProcess(sock);
    return NULL;
}

int server_start(char* ip,short port)
{
    int listen_sock = socket(AF_INET,SOCK_STREAM,0);
    if(listen_sock < 0)
    {
        perror("socket");
        return -1;
    }
    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);
    int ret = bind(listen_sock,(sockaddr*)&server,sizeof(server));
    if(ret < 0)
    {
        perror("bind");
        return -1;
    }
    ret = listen(listen_sock,5);
    if(ret < 0)
    {
        perror("listen");
        return -1;
    }
    int opt = 1;
    //设置reuseaddr，处理短连接
    setsockopt(listen_sock,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    return listen_sock;
}
int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("Usage:./server [ip] [port]\n");
        return 1;
    }
    signal(SIGCHLD,SIG_IGN);
    signal(SIGPIPE,SIG_IGN);
    //初始化服务器
    int listen_sock = server_start(argv[1],atoi(argv[2]));
    if(listen_sock < 0)
    {
        printf("server_start is failed");
        return 1;
    }
    printf("server_start OK\n");
    //进入循环处理事件
    while(1)
    {
        sockaddr_in peer;
        socklen_t len = sizeof(peer);
        int64_t new_sock = accept(listen_sock,(sockaddr*)&peer,&len);
        if(new_sock < 0)
        {
            perror("accept");
            continue;
        }
        //每来一个客户端,就创建一个线程去执行它对应的事情.
        pthread_t tid;
        //注意:这里采用多线程去处理每一个请求,
        //所以在这里传参时就要注意!!!不能引起线程安全问题,可以malloc一段空间,
        //但是要注意当使用结束后,要及时释放这段空间.
        //也可以传递一个临时变量,因为临时变量是属于某个线程的私有栈的东西.
        pthread_create(&tid,NULL,PthreadEntry,(void*)new_sock);
        //当线程处理完事情后,就要进行线程分离
        pthread_detach(tid);
    }
    return 0;
}
