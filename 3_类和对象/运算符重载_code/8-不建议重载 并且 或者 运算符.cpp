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
		cout << "ִ��&&���غ���" << endl;
		return i && obj.i;
	}
	Test operator+(const Test& obj)
	{
		cout << "ִ��+���غ���" << endl;
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
		cout << "��·ԭ��aΪ�٣����Բ�ִ����һ�����ʽ" << endl;
	}
	cout << "a = " << a << endl;
	cout << "-----------" << endl;

	Test t1(0), t2(1);
	if (t1 && (t2 + t1))
	{
		cout << "����������ִ�У�������ִ��+" << endl;
	}
	return 0;
}