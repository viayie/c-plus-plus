#include <stdio.h>

/*全局变量检测增强*/
int a;
int a = 10;

/*函数检测增强*/
getRectS(w, h)
{
    return w*h;
}
void test1()
{
    getRectS(10, 10, 10);
}

/*类型转换增强*/

/*struct增强*/
struct Person
{
    int age;
    //void func();//C语言结构体中不可以放函数
};
void test3()
{
    //Person p;//struct Person p;需要加struct关键字
}

/*bool类型*/

/*三目运算符加强*/
void test5()
{
    int a = 10;
    int b = 20;
    *(a>b ? &a : &b) = 40;//C++中三目运算符原理
}

/*const增强*/
const int m_a = 20;
void test6()
{
    //m_a = 200;

    int *p = &m_a;
    *p = 200;//m_a在常量区，语法通过，但运行出错

    const int m_b = 10;
    int *p = &m_b;
    *p = 100;
}

int main()
{

    return 0;
}