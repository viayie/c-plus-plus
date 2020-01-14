#include <iostream>

using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
		cout << "Parent(int)..." << endl;
	}
	void print()
	{
		cout << "Parent print" << endl;
	}
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int b) : Parent(9)
	{
		this->b = b;
		cout << "Child(int)..." << endl;
	}
	void print()
	{
		cout << "Child print" << endl;
	}
private:
	int b;
};

void howTOprint1(Parent* base)
{
	base->print();
}
void howTOprint2(Parent& base)
{
	base.print();
}

int main()
{
	Parent* base = NULL;

	Parent p1(20);
	Child c1(30);
	base = &p1;
	base->print();//执行父类打印
	base = &c1;
	base->print();//执行父类打印

	Parent& base1 = p1;
	base1.print();//执行父类打印
	Parent& base2 = c1;
	base2.print();//执行父类打印

	//函数调用
	howTOprint1(&p1);//执行父类打印
	howTOprint1(&c1);//执行父类打印
	howTOprint2(p1);//执行父类打印
	howTOprint2(c1);//执行父类打印

	return 0;
}