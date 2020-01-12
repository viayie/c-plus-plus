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
	friend Complex& operator++(Complex& c, int);
private:
	float _x, _y;
};

Complex& operator++(Complex& c, int)
{
	Complex t(c._x, c._y);
	c._x++;
	c._y++;

	return t;
}

int main()
{
	Complex c(10, 10);
	c.dis();//(10, 10)

	Complex c2 = c++;
	c2.dis();//(10, 10)
	c.dis();//(11, 11)

	c2 = c++++;
	//c2.dis();
	c.dis();//(12,12)

	return 0;
}
