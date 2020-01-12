#include <iostream>

using namespace std;

class Base
{
public:
	int pub;
protected:
	int pro;
private:
	int pri;
};

class Drive :public Base
{
public:
	void func()
	{
		pub = 10;
		pro = 9;
		pri = 8;//err
	}
};

int main()
{
	Base b;
	b.pub = 10;
	b.pro = 9;//err
	b.pri = 8;//err

	return 0;
}