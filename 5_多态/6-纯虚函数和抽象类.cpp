#include <iostream>

using namespace std;

//面向抽象类编程 （面向一套预先定义好的接口编程）

//抽象类
class Figure
{
public:
	//预定一个统一的接口，让子类使用，让子类必须去实现
	virtual void getArea() = 0;//纯虚函数
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
		cout << "圆的面积是 " << 3.14 * r * r << endl;
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
		cout << "正方形面积是" << a * a << endl;
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