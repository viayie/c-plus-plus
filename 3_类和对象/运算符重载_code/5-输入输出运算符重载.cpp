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
	friend ostream& operator<<(ostream &os, const Complex &c);
	friend istream& operator>>(istream &is, Complex& c);
private:
	float _x, _y;
};

//利用全局函数实现(因为要访问私有成员，所以借助友元)
//无法利用成员函数方式实现，因为ostream& operator<<(ostream& os) ---> c << cout;形式
ostream& operator<<(ostream& os, const Complex& c)
{
	os << "(" << c._x << ", " << c._y << ")";
	return os;//用于支持链式输出
}
istream& operator>>(istream& is, Complex& c)
{
	is >> c._x >> c._y;
	return is;
}
int main()
{
	Complex c(2, 3);
	cout << c << endl;

	cin >> c;	 
	cout << c << endl;

	Complex c1(4, 5);
	cout << c << c1 << endl;

	return 0;
}