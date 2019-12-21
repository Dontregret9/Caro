#ifndef __BOARD_H__
#define __BOARD_H__
#include<iostream>
#include<Windows.h>
#include"Point.h"
#include"Player.h"
using namespace std;
class Board
{
private:
	int size;
	int left, top;
	Point** pArr;
public:
	Board(int, int, int);
	~Board();
	int getSize();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);

	Point** getPoint()
	{
		return pArr;
	}
	static bool isEmptyBoard(int**, int, int);
	void resetData();
	void resetData(int**, int);
	void drawBoard();
	void writeName(int, int);
	int CheckBoard(int, int, bool);
	int TestBoard(int, int);
};
#endif