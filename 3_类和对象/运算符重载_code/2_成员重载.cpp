#include <iostream>

using namespace std;

class Complex
{
public:
	Complex(float x = 0, float y = 0) :_x(x), _y(y) {}
	void dis()
	{
		cout << _x << ", " << _y << endl;
	}

	friend const Complex operator+(const Complex& c1, const Complex& c2);
	const Complex operator+(const Complex& another);

private:
	float _x, _y;
};

const Complex operator+(const Complex& c1, const Complex& c2)
{
	cout << "友元函数重载" << endl;
	return Complex(c1._x + c2._x, c1._y + c2._y);
}

const Complex Complex::operator+(const Complex& another)
{
	cout << "成员函数重载" << endl;
	return Complex(this->_x + another._x, this->_y + another._y);
}

int main()
{
	Complex c1(2, 3), c2(3, 4);
	c1.dis();
	c2.dis();

	Complex c3 = c1 + c2;
	c3.dis();

	Complex c4 = operator+(c1, c2);
	c4.dis();

	Complex c5 = c1.operator+(c2);
	c5.dis();

	return 0;
}