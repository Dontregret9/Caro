#ifndef __PLAYGAME_H__
#define __PLAYGAME_H__
#include"Board.h"
#include"Common.h"
#include"Game.h"
#include"Point.h"
class PlayGame
{
public:
	void PlayNow(const int);
	void LoadGame(const int);
	void Setting(int);
	void Menu(int);
	void PlayWithComputer();
	void TwoPlayer();
	void Information();
};
#endif