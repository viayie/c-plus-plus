#include <iostream>
#include "point.h"
#include "circle.h"

using namespace std;

int main()
{
	Point p;
	p.set_XY(4, 8);

	Circle c;
	c.set_XY(1, 1);
	c.set_R(3);

	if (c.judgePoint(p))
		cout << "inside" << endl;
	else
		cout << "outside" << endl;

	return 0;
}