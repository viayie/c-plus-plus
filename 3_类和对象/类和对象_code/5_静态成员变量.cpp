#include <iostream>

using namespace std;

class Box
{
public:
	Box(int l, int w) :length(l), width(w)
	{
	}
	static int get_height()
	{
		return height;
	}
	int volume()
	{
		return length * width * height;
	}
private:
	int length;
	int width;
	static int height;
};

int Box::height = 10;

int main()
{
	cout << sizeof(Box) << endl;
	Box b(2, 3);
	cout << sizeof(b) << endl;

	cout << Box::get_height() << endl;
	cout << b.get_height() << endl;

	cout << b.volume() << endl;

	return 0;
}