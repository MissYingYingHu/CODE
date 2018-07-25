#include"WriteCopy2.h"

int main()
{
    String2 s1("hello");
    String2 s2(s1);
    String2 s3;
    s3 = s1;
    cout<<s1.c_str()<<endl;
    cout<<s2.c_str()<<endl;
    cout<<s3.c_str()<<endl;
    cout<<s1.GetRefCount()<<endl;
    cout<<s2.GetRefCount()<<endl;
    cout<<s3.GetRefCount()<<endl;
    cout<<s3[0]<<endl;
    cout<<s1.GetRefCount()<<endl;
    cout<<s2.GetRefCount()<<endl;
    return 0;
}

