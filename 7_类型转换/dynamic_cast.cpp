#include <iostream>

using namespace std;

//������������	������������������ת��
void test01()
{
	char c = 'c';
	//double d = dynamic_cast<double>(c);
}

//�Զ�����������
class Base
{
	virtual void func(){}
};
class Son:public Base
{
	void func(){}
};
class Other
{

};
void test02()
{
	Base *b = NULL;
	Son  *s = NULL;

	//bתΪSon* ��������ת�� ����ȫ
	//Son* s1 = dynamic_cast<Son*>(b);//ת��ʧ��

	//sתΪBase* ��������ת�� ��ȫ
	Base* b1 = dynamic_cast<Base*>(s);

	//base תΪ Other*
	//Other* o = static_cast<Other*>(b);//ת��ʧ��

	//���������̬�����������֮���ת�����ǰ�ȫ��
	Base* b2 = new Son;
	Son* s2 = dynamic_cast<Son*>(b2);
}

int main()
{

}
