#include "circle.h"

void Circle::set_XY(int x, int y)
{
	x0 = x;
	y0 = y;
}

void Circle::set_R(int r)
{
	m_r = r;
}

bool Circle::judgePoint(Point& p)
{
	int dis = (p.get_X() - x0) * (p.get_X() - x0) + (p.get_Y() - y0) * (p.get_Y() - y0);

	if (dis > m_r * m_r)
		return false;
	else
		return true;
}