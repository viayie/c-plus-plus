#include <iostream>

using namespace std;

/*引用：给一个内存起别名*/
void test01()
{
    int a = 10;
	int &b = a;

	a = 11;
	{
		int *p = &a;
		*p = 12;
		cout << "a = " << a << endl;
	}
	b = 22;
	cout << "a = " << a << ", b = " << b << endl;

}

/*引用规则*/
void test02()
{
    int a = 10;
    int b = 20;

    int &r = a;//声明的时候必须初始化
    //&r = b;//err 一经声明，不可改变原有的引用关系

    //float &R = b;//err 类型与原类型保持一致

    cout << &a << " " << &r << endl;//地址相同，引用不分配内存

    int &ra = r;//变量a 有两个别名：r, ra

    //建立对数组的引用1
    int arr[10];
    int (&parr)[10] = arr;
    
    //建立对数组的引用2：定义出数组的类型，再定义引用
    typedef int(ARRAY_TYPE)[10];
    ARRAY_TYPE &parr2 = arr;   
}

/*引用作函数参数*/
void swap(int &a, int &b)//声明的时候不进行初始化
{
	int tmp = a;
	a = b;
	b = tmp;
}
void test03()
{
	int num1 = 10;
	int num2 = 20;

	cout << "before swap: num1=" << num1 << ", num2=" << num2 << endl;
	swap(num1, num2);
	cout << "after  swap: num1=" << num1 << ", num2=" << num2 << endl;
}

/*引用作函数返回值*/
//返回栈变量的引用
int &getA1()
{
    int a = 10;
    return a;
}
void test04()
{
    //值拷贝
    int a1 = 0;
    a1 = getA1();
    cout << "a1 = " << a1 << endl;

    //将一个引用赋给另一个引用作为初始值，由于是栈的引用，内存非法
    int &a2 = getA1();
    cout << "a2 = " << a2 << endl;
}
//返回静态变量或全局变量
int &getA2()
{
    static int a = 10;
    return a;
}
void test05()
{
    int a1 = getA2();
    cout << "a1 = " << a1 << endl;

    int &a2 = getA2();
    cout << "a2 = " << a2 << endl;
}

/*指针的引用*/
struct Person
{
    int age;
};
void getSpace1(Person **p)
{
    *p = (Person*)malloc(sizeof(Person));
    (*p)->age = 20;
}
void getSpace2(Person* &p)
{
    p = (Person*)malloc(sizeof(Person));
    p->age = 30;
}
void test06()
{
    Person *p1;
    getSpace1(&p1);
    cout << p1->age << endl;

    Person *p2;
    getSpace2(p2);
    cout << p2->age << endl;
}

/*常量的引用*/

int main()
{
    test06();

    return 0;
}