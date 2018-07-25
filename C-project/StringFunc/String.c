#include"String.h"
#include<string.h>
#include<assert.h>
char* my_strcpy(char* dest,const char* src)
{
    assert(src && dest);
    char* d = dest;
    while(*d++ = *src++);
    return dest;
}
char* my_strcat(char* dest,const char* src)
{
    assert(dest && src);
    char* p = dest;
    while(*p)
    {
        ++p;
    }
    while(*p++ = *src++);
    return dest;
}
char* my_strstr(const char* src,const char* sub)
{
    assert(src && sub);
    char* str = (char*)src;
    char* s = (char*)sub;
    char* p = (char*)src;
    while(*str && *s)
    {
        str = p;
        s = (char*)sub;
        if(*str == *s)
        {
            while(*s == *str)
            {
                ++s;
                ++str;
            }
        }
        if(*s == '\0')
        {
            return str;
        }
        ++p;
    }
    return NULL;
}
void* my_memcpy(void* dest,const void* src,size_t size)
{
    assert(dest && src);
    char* d = (char*)dest;
    char* s = (char*)src;
    while(size--)
    {
        *d = *s;
        ++d;
        ++s;
    }
    return dest;
}
void* my_memmove(void* dest,const void* src,size_t size)
{
    assert(dest && src);
    char* d = (char*)dest;
    char* s = (char*)src;
    if(dest > src && ((char*)src + size) > (char*)dest)
    {
        d = (char*)dest + size - 1;
        s = (char*)src + size - 1;
        while(size--)
        {
            *d = *s;
            --s;
            --d;
        }
    }
    else
    {
        while(size--)
        {
            *d = *s;
            ++d;
            ++s;
        }
    }
    return dest;
}
///////////////////////////////////
int main()
{
    char src[30] = "happy";
    char dst[5] = "vert";
    char dest[30];
   // my_strcpy(dest,src);
   // printf("%s\n",dest);
   // my_strcat(dst,src);
   // printf("%s\n",dst);
   // my_strstr(dst,src);
   // my_memcpy(dest,src,6);
   // printf("%s\n",dest);
//    my_memmove(src,src,4);
//    printf("%s\n",my_memmove(src+2,src,3));
     printf("%s\n",memmove(src + 2,src,3));
    return 0;
}

