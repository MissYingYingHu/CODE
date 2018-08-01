#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


//对于收到的请求进行计算处理
static int GetRequest(char buf[])
{
  //1.首先要获取到环境变量
  char* method = getenv("REQUEST_METHOD");
  if(method == NULL)
  {
    fprintf(stderr,"method=NULL\n");
    return -1;
  }
  //2.对于不同的环境变量进行不同的处理
  if(strcasecmp(method,"GET") == 0)
  {
    char* quary = getenv("QUERY_STRING");
    if(quary == NULL)
    {
      fprintf(stderr,"quary=NULL\n");
      return -1;
    }
    strcpy(buf,quary);
  }
  else
  {
    char* content_length = getenv("CONTENT_LENGTH");
    if(content_length == 0)
    {
      fprintf(stderr,"content_length=0\n");
      return -1;
    }
    int length = atoi(content_length);
    char c = '\0';
    int i = 0;
    for(;i < length;++i)
    {
      read(0, &c, 1);
      buf[i] = c;
    }
    buf[length] = '\0';
  }
  return 0;
  
}
int main()
{
  char buf[1024*10] = {0};
  int ret = GetRequest(buf);
  if(ret < 0)
  {
    fprintf(stderr,"\nGetRequest failed.");
    return 1;
  }
  int a,b;
  sscanf(buf,"a=%d&b=%d",&a,&b);
  int sum = a + b;
  printf("<html><h1>sum=%d</h1></html>",sum);
  return 0;
}
