#include <iostream>
using namespace std;

class Test
{
public:
	Test()
	{
		m_a = 0;
		cout << "�޲ι��캯������" << endl;
	}
	Test(int a)
	{
		m_a = a;
		cout << "�вι��캯������" << endl;
	}
	Test(const Test& another_obj)
	{
		cout << "�������캯�����ã�ͨ����һ����������ʼ���Լ�" << endl;
		m_a = another_obj.m_a;
	}
	~Test()
	{
		cout << "������������" << endl;
	}
	void show()
	{
		cout << "m_a = " << m_a << endl;
	}

private:
	int m_a;
};

/*******��һ�������ʼ����һ������*******/
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

/*******�����β���һ������*******/
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

/*******��������ֵ��һ������*******/
Test func1()
{
	cout << "func1 begin..." << endl;
	Test tmp(10);
	cout << "func1 end..." << endl;
	return tmp;
}

int main()
{
	/***�����պ�������ֵ***/
	//func1();�����պ�������ֵ

	/***��һ���µĶ�����պ�������ֵ***/
	//Test t1 = func1();
	//t1.show();

	/***��һ�����еĶ���ȥ���� �������صĶ���***/
	Test t1;
	t1 = func1();
	t1.show();

	return 0;
}
