#include <stdio.h>

/*全局*/
const int m_A = 200;//全局const受到常量区保护
void test01()
{
    int *p = &m_A;
    *p = 100;//语法通过，运行阶段报错。
}

/*局部*/
//修饰的是 只读变量 ， 本质上仍是变量，有自己存储空间
void test02()
{
    const int m_B = 200;
    int *p = &m_B;
    *p = 100;//可以间接修改

    int arr[m_B];//err 不可以初始化数组
}

/*const在C语言下默认是外部链接属性*/
void test03()
{
    //在另一个.c文件中有 const int m_C = 20;
    extern const int m_C;

    printf("m_C = %d\n", m_C);
}




int main()
{
    test02();

    return 0;
}