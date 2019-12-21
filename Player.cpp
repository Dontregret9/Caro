#include"Player.h"
Player::Player()
{
	name = "";
	play = 0;
	buoc = 0;
}
Player::Player(string str, int tran, int sobuoc)
{
	buoc = sobuoc;
	name = str;
	play = tran;
}
Player::Player(Player* temp)
{
	name = temp->name;
	play = temp->play;
	buoc = temp->buoc;
}
Player::~Player() {};
string Player::getName()
{
	return name;
}
int Player::getPlay()
{
	return play;
}
void Player::setName(string str)
{
	name = str;
}
void Player::setPlay(int tran)
{
	play = tran;
}