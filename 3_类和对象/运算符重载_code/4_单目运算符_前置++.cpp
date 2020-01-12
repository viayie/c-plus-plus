#include <iostream>

using namespace std;

class Complex
{
public:
	Complex(float x = 0, float y = 0) :_x(x), _y(y) {}
	void dis()
	{
		cout << "(" << _x << ", " << _y << ")" << endl;
	}
	friend Complex& operator++(Complex& c);
private:
	float _x, _y;
};

Complex& operator++(Complex &c)
{
	c._x++;
	c._y++;

	return c;
}

int main()
{
	Complex c(10, 10);
	c.dis();//(10, 10)

	Complex c2 = ++c;
	c2.dis();//(11, 11)
	c.dis();//(11, 11)

	c2 = ++++c;
	c2.dis();//(13,13)
	c.dis();//(13,13)

	return 0;
}
