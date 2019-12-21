#ifndef __PLAYER_H__
#define __PLAYER_H__
#include<iostream>
#include<string>
using namespace std;
class Player
{
	int buoc;
	string name;
	int play;
public:
	Player();
	Player(string, int, int);
	Player(Player*);
	~Player();
	void setName(string);
	void setPlay(int);
	string getName();
	int getPlay();
	int getBuoc()
	{
		return buoc;
	}
	void setBuoc(int n)
	{
		buoc = n;
	}
};
#endif
