#include"WriteCopy.h"


int main()
{
    String s1("hello");
    String s2(s1);
    String s3;
    s3 = s1;
    cout<<s3[0]<<endl;
    cout<<s1.c_str()<<endl;
    cout<<s2.c_str()<<endl;
    cout<<s3.c_str()<<endl;
    return 0;

}
