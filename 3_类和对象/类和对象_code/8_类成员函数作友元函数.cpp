#include <iostream>
#include <cmath>

using namespace std;

class Point;
//ǰ����������һ�ֲ���ȫ��������ֻ���ṩ�����������ṩ��ʵ�֣����ɡ�
//�������� ����ָ�������

class ManagerPoint
{
public:
	double Distance(Point &a, Point &b);
};

class Point
{
public:
	Point(double xx, double yy):x(xx), y(yy)
	{}
	friend double ManagerPoint::Distance(Point& a, Point& b);
private:
	double x, y;
};

double ManagerPoint::Distance(Point& a, Point& b)
{
	double dx = a.x - b.x;
	double dy = a.y - b.y;

	return sqrt(dx*dx + dy*dy);
}

int main()
{
	Point p1(1.2, 2.5), p2(5.6, 4.9);

	ManagerPoint mp;
	cout << "distance : " << mp.Distance(p1, p2) << endl;

	return 0;
}
