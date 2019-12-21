#include"Point.h"
Point::Point() {
	x = y = check = 0;
}
Point::Point(int pX, int pY)
{
	x = pX;
	y = pY;
	check = 0;
}

int Point::GetX()
{
	return x;
}
int Point::GetY()
{
	return y;
}
int Point::GetCheck()
{
	return check;
}
void Point::setX(int pX)
{
	x = pX;
}
void Point::setY(int pY)
{
	y = pY;
}
bool Point::setCheck(int pCheck)
{
	if (pCheck == -1 || pCheck == 1 || pCheck == 0)
	{
		check = pCheck;
		return true;
	}
	return false;
}