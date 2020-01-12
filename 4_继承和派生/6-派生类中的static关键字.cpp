#include <iostream>

using namespace std;

class Parent
{
public:
	static int a;
};

int Parent::a = 100;

class Child: public Parent
{
public:
	void dis()
	{
		cout << "a = " << a << endl;
	}
};

int main()
{
	Child c;
	c.dis();

	return 0;
}