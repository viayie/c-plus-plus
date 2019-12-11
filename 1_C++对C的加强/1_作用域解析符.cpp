#include <iostream>
using namespace std;

int a = 10;

int main()
{
    int a = 20;

    cout << "局部变量值为：" << a << endl;
    cout << "全局变量值为：" << ::a << endl;

    return 0;
}