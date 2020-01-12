#include <iostream>

using namespace std;

class Point
{
public:
	Point(double xx, double yy)
	{
		x = xx;
		y = yy;
	}
	friend double Distance(Point &a, Point &b);
private:
	double x;
	double y;
};

double Distance(Point& a, Point& b)
{
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}
int main()
{
	Point p1(1.34, 2.56);
	Point p2(8.25, 9.62);
	cout << "distance : " << Distance(p1, p2) << endl;

	return 0;
}