#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"Player.h"
#include"Board.h"
using namespace std;
class Game
{
	Player Who1;
	Player Who2;
	Board* b;
	bool turn;
	int x, y;
	int command;
	bool loop;
public:
	Game(int, int, int);
	~Game();
	void setTurn(bool turn_temp)
	{
		turn = turn_temp;
	}
	Board* getBoard()
	{
		return b;
	}
	Player getPlayer1()
	{
		return Who1;
	}
	Player getPlayer2()
	{
		return Who2;
	}
	int getCommand();
	bool isContinue();
	char waitKeyboard();
	char askContinue();
	void startGame();
	void startGame(int**, int);
	void exitGame(string, int);
	void exitGame();
	int processFinish();// kiểm tra xem đã kết thúc chưa sau mỗi bước đi
	bool processCheckBoard();// kiểm tra vị trí con trỏ đã có cờ chưa
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
};