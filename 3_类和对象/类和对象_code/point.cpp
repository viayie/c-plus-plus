#include "point.h"

void Point::set_XY(int x, int y)
{
	m_x = x;
	m_y = y;
}

int Point::get_X()
{
	return m_x;
}

int Point::get_Y()
{
	return m_y;
}