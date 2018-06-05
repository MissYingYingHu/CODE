//把字符串中的空格字符替换为%20
//we are happy. ---------> we%20are%20%20happy.
#include<stdio.h>
#include<string.h>
//先从前往后遍历,遇到一个空格,就往后移动两个字节,然后插入.
//时间复杂度是O^2
//方法2：统计出所有的空格数，然后将字符串的长度重新确定。
//时间复杂度是O(N)
void Replace2(char str[],size_t len)
{
    if(str == NULL && len <= 0)
    {
        return;
    }
    size_t blank = 0;
    size_t originalLength = 0;
    size_t i = 0;
    while(str[i] != '\0')
    {
        ++originalLength;
        if(str[i] == ' ')
        {
            ++blank;
        }
        ++i;
    }
    size_t new_len = originalLength + blank * 2;
    if(new_len <= len)
    {
        return;
    }
    int new_end = (int)new_len;
    int old_end = (int)originalLength;
    while(old_end >= 0 && new_end > old_end)
    {
        if(str[old_end] == ' ')
        {
            str[new_end--] = '0';
            str[new_end--] = '2';
            str[new_end--] = '%';
        }
        else
        {
            str[new_end--] = str[old_end];
        }
        --old_end;
    }
}
int main()
{
 //   char str[] = "             ";
    char str[] = " we are      happy. ";
 //   char str1[] = "happy.";
    size_t len = sizeof(str)/sizeof(str[0]);
    Replace2(str,len);
    printf("%s\n",str);
    return 0;
}
