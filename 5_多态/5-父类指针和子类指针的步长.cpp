#include <iostream>

using namespace std;

class  Parent
{
public:
	Parent(int a)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout << "Parent::paint()... a = " << a << endl;
	}
	int a;
};

class Child : public Parent
{
public:
	Child(int a):Parent(a)
	{
	}
	virtual void print()
	{
		cout << "Child::paint()... a = " << a << endl;
	}
};

class Child1 : public Parent
{
public:
	Child1(int a, int b) :Parent(a)
	{
		this->b = b;
	}
	virtual void print()
	{
		cout << "Child1::paint()... a = " << a << endl;
	}
	int b;
};

int main()
{
	Child array[] = {Child(0), Child(1), Child(2)};
	Child1 array1[] = { Child1(0, 0), Child1(1, 1), Child1(2, 2) };

	Parent* pP  = array;

	for (int i = 0; i<3; i++, pP++)
	{
		pP->print();
		//cP->print();
	}

	Parent* pP1 = array1;
	for (int i = 0; i < 3; i++, pP1++)//err
	{
		pP1->print();
	}

	return 0;
}
