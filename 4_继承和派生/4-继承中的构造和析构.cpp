#include <iostream>

using namespace std;

class Parent
{
public:
	Parent()
	{
		a = 0;
		cout << "Parent()..." << endl;
	}
	Parent(int a)
	{
		this->a = a;
		cout << "Parent(int)..." << endl;
	}
	~Parent()
	{
		cout << "~Parent()..." << endl;
	}
	int a;
};

class Child: public Parent
{
public:
	Child(int a, int b):Parent(a)
	{
		this->b = b;
		cout << "Child(int, int)..." << endl;
	}
	void dis()
	{
		cout << "a=" << a << ", b=" << b << endl;
	}
	~Child()
	{
		cout << "~Child()..." << endl;
	}
	int b;

};

int main()
{
	Child c(10, 20);
	c.dis();

	return 0;
}