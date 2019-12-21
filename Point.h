#ifndef __POINT_H__
#define __POINT_H__
#include<iostream>
#include<Windows.h>
using namespace std;
class Point
{
	int x, y, check;
public:
	Point();
	Point(int, int);
	bool setCheck(int);
	int GetX();
	int GetY();
	int GetCheck();
	void setX(int);
	void setY(int);
};
#endif