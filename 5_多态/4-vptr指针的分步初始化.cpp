#include <iostream>

using namespace std;

class Parent
{
public:
	Parent(int a)
	{
		this->a = a;
		cout << "Parent()..." << endl;

		/*****���캯���е����麯��******/
		func();
	}
	virtual void func()
	{
		cout << "Parent::func()..." << endl;
	}
	int a;
};
class Child : public Parent
{
public:
	Child(int a, int b):Parent(a)//
	{
		this->b = b;
		cout << "Child()..." << endl;
	}
	virtual void func()
	{
		cout << "Child::func()..." << endl;
	}
	int b;
};

int main()
{
	Child c(1, 2);

	return 0;
}