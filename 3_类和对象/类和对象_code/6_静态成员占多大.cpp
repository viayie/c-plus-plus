#include <iostream>

using namespace std;

class C1
{
public:
	int i;
	int j;
	int k;
};

class C2
{
public:
	int i;
	int j;
	int k;
	static int m;
public:
	int getK() const
	{
		return k;
	}
	void setK(int val)
	{
		k = val;
	}
};

struct S1
{
	int i;
	int j;
	int k;
};

struct S2
{
	int i;
	int j;
	int k;
	static int m;
};

int main()
{
	cout << "c1: " << sizeof(C1) << endl;
	cout << "c2: " << sizeof(C2) << endl;
	cout << "s1: " << sizeof(S1) << endl;
	cout << "s2: " << sizeof(S2) << endl;

	return 0;
}
