#include <iostream>

using namespace std;

class Complex
{
public:
	Complex(float x=0, float y=0):_x(x), _y(y){}
	void dis()
	{
		cout << "(" << _x << "," << _y << ")" << endl;
	}
	Complex& operator+=(const Complex& c)
	{
		this->_x += c._x;
		this->_y += c._y;
		return *this;
	}

private:
	float _x, _y;
};

int main()
{
	// += 重载函数返回 void
	Complex a1(10, 0), b1(20, 0), c1(30, 0);
	a1 += b1;
	a1.dis();//(30,0)

	// += 重载函数返回 Complex
	Complex a2(10, 0), b2(20, 0), c2(30, 0);
	a2 += b2 += c2;
	a2.dis();//(60,0)

	// += 重载函数返回 Complex &
	Complex a3(10, 0), b3(20, 0), c3(30, 0);
	(a3 += b3) += c3;
	a3.dis();//(60,0)
	b3.dis();//(20,0)
	c3.dis();//(30,0)

	return 0;
}