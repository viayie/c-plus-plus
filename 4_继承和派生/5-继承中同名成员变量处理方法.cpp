#include <iostream>

using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
	}
	int a;
};
class Child : public Parent
{
public:
	Child(int p_a, int c_a) :Parent(p_a)
	{
		this->a = c_a;
	}
	int a;//Í¬Ãû
	void dis()
	{
		cout << Parent::a << endl;
		cout << a << endl;
	}
};

int main()
{
	Child c(10, 4);
	c.dis();

	return 0;
}