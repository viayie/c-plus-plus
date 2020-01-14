#include <iostream>
#include <cstring>

using namespace std;

class A
{
public:
	A()
	{
		p = new char[20];
		strcpy_s(p, strlen("A string...")+1, "A string...");
		cout << "A()... " << endl;
	}
	virtual ~A()
	{
		delete[] p;
		cout << "~A()... " << endl;
	}
private:
	char* p;
};

class B : public A 
{
public:
	B()
	{
		p = new char[20];
		strcpy_s(p, strlen("B string...")+1, "B string...");
		cout << "B()... " << endl;
	}
	~B()
	{
		delete[] p;
		cout << "~B()... " << endl;
	}
private:
	char* p;
};

void howtodelete(A *base)
{
	delete base;
}

int main()
{
	B *b = new B;
	howtodelete(b);

	return 0;
}
