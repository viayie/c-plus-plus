#include <iostream>

using namespace std;

/*全局变量检测增强*/
// int a;
// int a = 10;

/*函数检测增强*/
//形参变量类型增强、函数声明的返回值检测增强、函数返回值检测增强、调用函数参数个数检测增强
// getRectS(w, h)
// {
//     return w*h;
// }
// void test1()
// {
//     getRectS(10, 10, 10);
// }

/*类型转换增强*/

/*struct增强*/
struct Person
{
    int age;
    //void func();//C++语言结构体中可以放函数
};
void test3()
{
    Person p;
}

/*bool类型*/
void test4()
{
    cout << "bool类型占字节大小:" << sizeof(bool) << endl;//1
}

/*三目运算符加强*/
void test5()
{
    int a = 10;
    int b = 20;
    (a>b ? a : b) = 40;//作为左值使用
    cout << "a=" << a << ", b=" << b << endl;

}

int main()
{

    return 0;
}