#include <iostream>

using namespace std;

class Bed
{
public:
	void sleep()
	{
		cout << "sleep..." << endl;
	}
};

class Sofa
{
public:
	void sit()
	{
		cout << "sit..." << endl;
	}
};

class SofaBed: public Sofa, public Bed
{
public:
	void sleepANDsit()
	{
		sleep();
		sit();
	}
};

int main()
{
	SofaBed sb;
	sb.sleepANDsit();

	return 0;
}