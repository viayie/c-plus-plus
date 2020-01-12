#pragma once
#include "point.h"

class Circle
{
public:
	void set_XY(int x, int y);
	void set_R(int r);
	bool judgePoint(Point& p);

private:
	int x0;
	int y0;
	int m_r;
};
