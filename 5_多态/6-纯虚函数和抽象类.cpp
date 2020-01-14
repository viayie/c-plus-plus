#include <iostream>

using namespace std;

//����������� ������һ��Ԥ�ȶ���õĽӿڱ�̣�

//������
class Figure
{
public:
	//Ԥ��һ��ͳһ�Ľӿڣ�������ʹ�ã����������ȥʵ��
	virtual void getArea() = 0;//���麯��
};

class Circle : public Figure
{
public:
	Circle(int r)
	{
		this->r = r;
	}
	virtual void getArea()
	{
		cout << "Բ������� " << 3.14 * r * r << endl;
	}
private:
	int r;
};

class Square : public Figure
{
public:
	Square(int a)
	{
		this->a = a;
	}
	virtual void getArea()
	{
		cout << "�����������" << a * a << endl;
	}
private:
	int a;
};

void area_func(Figure* base)
{
	base->getArea();
}

int main()
{
	//Figure f;//err
	Figure* cir = new Circle(4);
	Figure* sqr = new Square(2);

	area_func(cir);
	area_func(sqr);

	return 0;
}