﻿#include"Common.h"
#include"Board.h"
#include"Game.h"
#include"Point.h"
#include"PlayGame.h"
const int kichthuoc = 20;
void main()
{
	for (int i = 1; i < 10; i++)
	{
		cout << "\n\n\n\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		cout << "\t\t\t .----------------.  .----------------.  .----------------.  .----------------. \n";
		cout << "\t\t\t| .--------------.|| .--------------. || .--------------. || .--------------. |\n";
		cout << "\t\t\t||     ______   | || |      __      | || |  _______     | || |     ____     | |\n";
		cout << "\t\t\t||   .' ___  |  | || |     /  \\     | || | |_   __ \\    | || |   .'    `.   | |\n";
		cout << "\t\t\t||  /.'    \\_|  | || |    / /\\ \\    | || |   | |__) |   | || |  /  .--.  \\  | |\n";
		cout << "\t\t\t||  | |         | || |   / ____ \\   | || |   |  __ /    | || |  | |    | |  | |\n";
		cout << "\t\t\t||  \\ `.___.'\\  | || | _/ /    \\ \\_ | || |  _| |  \\ \\_  | || |  \\  `--'  /  | |\n";
		cout << "\t\t\t||   `._____.'  | || ||____|  |____|| || | |____| |___| | || |   `.____.'   | |\n";
		cout << "\t\t\t||              | || |              | || |              | || |              | |\n";
		cout << "\t\t\t|'--------------' || '--------------' || '--------------' || '--------------' |\n";
		cout << "\t\t\t '----------------'  '----------------'  '----------------'  '----------------' \n";
		Sleep(200);
		system("cls ");
	}
	PlayGame p;
	p.Menu(kichthuoc);
}


