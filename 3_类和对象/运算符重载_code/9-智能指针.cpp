#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
	A(int a)
	{
		cout << "A constructor" << endl;
		this->a = a;
	}
	~A()
	{
		cout << "A destructor" << endl;
	}
	void dis()
	{
		cout << "a = " << a << endl;
	}
private:
	int a;
};

class MyAutoPtr
{
public:
	MyAutoPtr(A* ptr)
	{
		this->ptr = ptr;
	}
	~MyAutoPtr()
	{
		if (this->ptr != NULL)
		{
			cout << "delete ptr" << endl;
			delete ptr;
			this->ptr = NULL;
		}
	}
	A* operator->()
	{
		return this->ptr;
	}
	A& operator*()
	{
		return *ptr;
	}
private:
	A* ptr;
};

int main()
{
	//auto_ptr<A> ptr(new A(10));
	MyAutoPtr my_p(new A(10));
	my_p->dis();	//my_p.ptr->dis();
	(*my_p).dis();	//*ptr.dis();
	return 0;
}
