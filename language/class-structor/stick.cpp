#include<iostream>
using namespace std;
int main()
{
    int a = 10;
    // *p是个指针类型
    int *p = &a;
    // 这里的*p代表取p这个地址上的值
    *p = 9;
    cout << a << endl;
    return 0;
}

