#include <iostream>

using namespace std;

class Complex
{
	friend const Complex operator+(const Complex& c1, const Complex& c2);

public:
	Complex(float x=0, float y=0):_x(x), _y(y) {}
	void dis()
	{
		cout << _x << ", " << _y << endl;
	}

private:
	float _x, _y;
};

const Complex operator+(const Complex& c1, const Complex& c2)
{
	return Complex(c1._x+c2._x, c1._y+c2._y);
}


int main()
{
	Complex c1(2, 3), c2(3, 4);
	c1.dis();
	c2.dis();

	Complex c3 = c1 + c2;
	//Complex c3 = operator(c1, c2);
	c3.dis();

	return 0;
}