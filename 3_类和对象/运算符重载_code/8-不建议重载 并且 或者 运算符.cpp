#include <iostream>

using namespace std;

class Test
{
public:
	Test(int i=0)
	{
		this->i = i;
	}
	bool operator&&(const Test& obj)
	{
		cout << "执行&&重载函数" << endl;
		return i && obj.i;
	}
	Test operator+(const Test& obj)
	{
		cout << "执行+重载函数" << endl;
		Test ret(i + obj.i);
		return ret;
	}
private:
	int i;
};

int main()
{
	int  a = 0;
	if (a && (a = 10))
	{
		cout << "短路原则：a为假，所以不执行下一个表达式" << endl;
	}
	cout << "a = " << a << endl;
	cout << "-----------" << endl;

	Test t1(0), t2(1);
	if (t1 && (t2 + t1))
	{
		cout << "两个函数都执行，并且先执行+" << endl;
	}
	return 0;
}