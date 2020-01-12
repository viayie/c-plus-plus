#include <iostream>

using namespace std;

class Parent
{
public:
	void printP()
	{
		cout << "Parent..." << endl;
	}
};

class Child: public Parent
{
public:
	void printC()
	{
		cout << "Child..." << endl;
	}
};

void print1(Parent *p)
{
	p->printP();
}

void Print2(Parent& p)
{
	p.printP();
}

int main()
{
	Child c1;
	c1.printC();

	//����ָ��ָ���������
	Parent* p = NULL;
	p = &c1;
	p->printP();//ִ�и���ĺ���

	Child c2;
	Parent p2;

	print1(&p2);
	print1(&c2);//����ָ��ָ���������

	Print2(p2);
	Print2(c2);//��������ָ���������

	//��������ʼ���������
	Child c3;
	Parent p3 = c3;

	return 0;
}