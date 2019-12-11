#include <iostream>
#include <string>

using namespace std;

/*全局*/
const int m_A = 200;//全局const受到常量区保护
void test01()
{
    int *p = (int *)&m_A;
    *p = 100;//语法通过，运行阶段报错。
}

/*局部*/
void test02()
{
    const int m_B = 200;//被编译器放到符号表中去
    int *p = (int *)&m_B;
    *p = 100;

    cout << "m_B = " << m_B << endl;
    //修改不成功，使用时，值是从符号表获取，而不是分配的存储空间的值

    int arr[m_B];//可以初始化数组 常量
}

/*const在C++下默认是内部部链接属性*/
void test03()
{
    //在另一个.c文件中有 const int m_C = 20;
    extern const int m_C;

    cout << m_C << endl;//报错

    //修改另一.c文件中为 extern const int m_C = 20;
    cout << m_C << endl;//通过
}

/*const分配内存情况*/
//1、对const修饰的变量取地址，会分配临时内存

//2、const修饰的变量前加 extern 关键字

//3、使用变量来初始化const修饰的变量
void test04()
{
    int a = 10;
    const int m_D = a;
    int *p = (int *)m_D;
    *p = 20;
    cout << m_D << endl;//修改成功
}

//4、const修饰自定义数据类型
struct Person
{
    string name;
    int age;
};
void test05()
{
    const Person p;
    // p.name = "aaa";//err
    // p.age = 10;//err

    Person *pp = (Person*)&p;
    pp->name = "aaa";//OK
    pp->age = 10;//OK
}

/*尽量利用const代替#define*/
//1. 宏常量没有类型
//2. 不重视作用域


int main()
{
    test02();
    return 0;
}