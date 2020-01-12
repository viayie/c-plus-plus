#include <iostream>
using namespace std;

class Sqr
{
public:
	int operator()(int i)
	{
		return i * i;
	}
	double operator()(double d)
	{
		return d * d;
	}
};

int main()
{
	Sqr sqr;

	int i = sqr(4);
	double d = sqr(5.5);

	cout << i << endl;
	cout << d << endl;
	return 0;
}