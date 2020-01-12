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

//����ȫ�ֺ���ʵ��(��ΪҪ����˽�г�Ա�����Խ�����Ԫ)
//�޷����ó�Ա������ʽʵ�֣���Ϊostream& operator<<(ostream& os) ---> c << cout;��ʽ
ostream& operator<<(ostream& os, const Complex& c)
{
	os << "(" << c._x << ", " << c._y << ")";
	return os;//����֧����ʽ���
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