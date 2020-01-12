#include <iostream>
using namespace std;

class Test
{
public:
	Test()
	{
		m_a = 0;
		cout << "无参构造函数调用" << endl;
	}
	Test(int a)
	{
		m_a = a;
		cout << "有参构造函数调用" << endl;
	}
	Test(const Test& another_obj)
	{
		cout << "拷贝构造函数调用，通过另一个对象来初始化自己" << endl;
		m_a = another_obj.m_a;
	}
	~Test()
	{
		cout << "析构函数调用" << endl;
	}
	void show()
	{
		cout << "m_a = " << m_a << endl;
	}

private:
	int m_a;
};

/*******用一个对象初始化另一个对象*******/
int main1()
{
	Test t1(10);
	Test t2 = t1;
	t2.show();
	return 0;
}

int main2()
{
	Test t1(10);
	Test t2(t1);
	t2.show();

	return 0;
}

/*******函数形参是一个对象*******/
void func(Test t)
{
	cout << "func begin..." << endl;
	t.show();
	cout << "func end...  " << endl;
}
int main3()
{
	Test t1(10);
	func(t1);

	return 0;
}

/*******函数返回值是一个对象*******/
Test func1()
{
	cout << "func1 begin..." << endl;
	Test tmp(10);
	cout << "func1 end..." << endl;
	return tmp;
}

int main()
{
	/***不接收函数返回值***/
	//func1();不接收函数返回值

	/***用一个新的对象接收函数返回值***/
	//Test t1 = func1();
	//t1.show();

	/***用一个已有的对象去接收 函数返回的对象***/
	Test t1;
	t1 = func1();
	t1.show();

	return 0;
}
