#include<fstream>
#include"Game.h"
#include"Common.h"
Game::Game(int pSize, int pLeft, int pTop)
{
	b = new Board(pSize, pLeft, pTop);
	loop = turn = true;
	command = -1;
	x = pLeft;
	y = pTop;
}
Game::~Game()
{
	delete b;
}

int Game::getCommand() {
	return command;
}
bool Game::isContinue()
{
	return loop;
}
char Game::waitKeyboard()
{
	command = toupper(_getch());
	return command;
}
char Game::askContinue()
{
	Common::gotoXY(0, b->getYAt(b->getSize() - 1, b->getSize() - 1) + 4);
	return waitKeyboard();
}
void Game::startGame() // khởi động game mới
{
	system("cls");
	b->resetData();
	b->drawBoard();
	b->writeName(0, 0);
	x = b->getXAt(0, 0);
	y = b->getYAt(0, 0);
}
void Game::startGame(int** BanCo, int turn2)// khởi động game từ file
{
	system("cls");
	b->resetData(BanCo, turn2);
	b->drawBoard();
	int n1 = 0, n2 = 0;// số quân cờ mỗi người đã đi
	for (int i = 0; i< b->getSize(); i++)
	{
		for (int j = 0; j < b->getSize(); j++)
		{
			if (BanCo[i][j] == -1)
			{
				Common::gotoXY(b->getPoint()[i][j].GetX(), b->getPoint()[i][j].GetY());
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				cout << "X";
				n1 = Who1.getBuoc();
				n1 = n1 + 1;
				Who1.setBuoc(n1);
				Common::gotoXY(4 * b->getSize() + b->getLeft() + 36, 4);
				cout << n1;
			}
			if (BanCo[i][j] == 1)
			{
				Common::gotoXY(b->getPoint()[i][j].GetX(), b->getPoint()[i][j].GetY());
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << "O\a";
				n2 = Who2.getBuoc();
				n2 = n2 + 1;
				Who2.setBuoc(n2);
				Common::gotoXY(4 * b->getSize() + b->getLeft() + 36, 9);
				cout << n2;
			}
		}
	}
	b->writeName(n1, n2);
	x = b->getXAt(0, 0);
	y = b->getYAt(0, 0);
}
void Game::exitGame()// thoát game mà không cần lưu game lại
{
	system("cls");
	loop = false;
}
void Game::exitGame(string filename, int size)// thoát game và lưu vào file
{
	fstream f;
	f.open(filename, ios::in | ios::out | ios::trunc);
	if (f.is_open())
	{// lưu lại lượt đi
		if (turn)
		{
			int turn_temp = 1;// chuyển từ dạng bool về dạng int để lưu trữ
			f << turn_temp;
		}
		else
		{
			int turn_temp = -1;// chuyển từ dạng bool về dạng int để lưu trữ
			f << turn_temp;
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				f << " " << b->getPoint()[i][j].GetCheck() << " ";// ghi bảng vào file, giữa các kí tự  có khoảng cách
			}
		}
		f.close();
	}
	system("cls");
	loop = false;
}
bool Game::processCheckBoard()// quyết định điền vào bàn cờ hay không
{
	switch (b->CheckBoard(x, y, turn))
	{
	case -1:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		cout << "X\a";
		int n1 = Who1.getBuoc();
		n1 = n1 + 1;// tăng số quân cờ đã đi của người chơi 1
		Who1.setBuoc(n1);//
		Common::gotoXY(4 * b->getSize() + b->getLeft() + 36, 4);
		cout << n1;// thay đổi hiển thị số quân cờ của người chơi 1 trên màn hình
		break;
	}
	case 1:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "O\a";
		int n2 = Who2.getBuoc();
		n2 = n2 + 1;
		Who2.setBuoc(n2);
		Common::gotoXY(4 * b->getSize() + b->getLeft() + 36, 9);
		cout << n2;
		break;
	}
	case 0: return false;
	}
	return true;
}
int Game::processFinish()// kiểm tra xem đã thắng thua hay hòa hoặc chưa có gì thi đi tiếp
{
	Common::gotoXY(0, b->getYAt(b->getSize() - 1, b->getSize() - 1) + 2);
	int pWhoWin = b->TestBoard(x, y);// x,y là tọa độ console
	switch (pWhoWin)
	{
	case 1:
		for (int i = 0; i < 20; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
			Common::gotoXY(4 * b->getSize() + b->getLeft() + 11, 20);
			cout << "Player 2 won \n";
			Sleep(200);
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case -1:
		for (int i = 0; i < 20; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
			Common::gotoXY(4 * b->getSize() + b->getLeft() + 11, 20);
			cout << "Player 1 won \n";
			Sleep(200);
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case 2:
		turn = !turn;
		break;
	case 0:
		Common::gotoXY(4 * b->getSize() + b->getLeft() + 11, 20);
		cout << "You are drawn\n";
		break;
	}
	if (pWhoWin == 1 || pWhoWin == -1 || pWhoWin == 0)
	{
		Who2.setBuoc(0);
		Who1.setBuoc(0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		Common::gotoXY(4 * b->getSize() + b->getLeft() + 11, 22);
		cout << "Do you want to play again ?\n";
		Common::gotoXY(4 * b->getSize() + b->getLeft() + 11, 23);
		cout << "Press 'Y' to CONTINUE and any other key to BACK TO MENU \n";
		if (askContinue() != 'Y')
		{
			exitGame();
		}
		else
			startGame();
	}
	Common::gotoXY(x, y);
	return pWhoWin;
}
void Game::moveRight()
{
	if (x < b->getXAt(b->getSize() - 1, b->getSize() - 1))
	{
		x += 4;
		Common::gotoXY(x, y);
	}
}
void Game::moveLeft()
{
	if (x > b->getXAt(0, 0))
	{
		x -= 4;
		Common::gotoXY(x, y);
	}
}
void Game::moveDown()
{
	if (y < b->getYAt(b->getSize() - 1, b->getSize() - 1))
	{
		y += 2;
		Common::gotoXY(x, y);
	}
}
void Game::moveUp()
{
	if (y > b->getYAt(0, 0))
	{
		y -= 2;
		Common::gotoXY(x, y);
	}
}