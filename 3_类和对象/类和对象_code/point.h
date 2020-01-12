#pragma once

class Point
{
public:
	void set_XY(int x, int y);
	int get_X();
	int get_Y();

private:
	int m_x;
	int m_y;
};