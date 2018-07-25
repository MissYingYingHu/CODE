#include <iostream>
using namespace std;

float fun(int n)
{
    if(n < 1)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    int i = 2;
    float sum = 0;
    while(i <= n)
    {
        sum += 1.0/i;
        ++i;
    }
    return sum + 1;
    //else
    //{
    //    return 1.0/n + fun(n - 1);
    //}
}

int main()
{
    cout<<fun(5)<<endl;
    return 0;
}
