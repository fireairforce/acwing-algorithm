#include<iostream>
using namespace std;
// 全局变量是放在一个堆空间里面
char a, b;
int main()
{
    // 局部变量是放在一个栈空间里面的
    char c = 'a';
    cout << (void *)&c << endl;
    char d;
    cout << (void *)&d << endl;

    // 输出堆空间里面变量的地址
    cout << (void *)&a << endl;
    cout << (void *)&b << endl;

    // 数组其实就是个指针
    int arr[] = {1,2, 3,4,5};
    char s;
    // 这里这两个地址值会是连续的
    cout << arr << endl;
    cout << (void *) &s << endl;

    // 使用指针来输出数组里面的值(使用*来取到指针的地址值)
    cout << *(arr + 2) << endl;

    int x = 10;
    // int *y = &p;
    // 这里 & 可以理解为取了个别名
    int &y = x;
    return 0;
}

