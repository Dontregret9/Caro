#include"Board.h"
#include"Common.h"
#include"Player.h"
int Board::getSize()
{
	return size;
}
int Board::getLeft()
{
	return left;
}
int Board::getTop()
{
	return top;
}
int Board::getXAt(int i, int j)
{
	return pArr[i][j].GetX();
}
int Board::getYAt(int i, int j)
{
	return pArr[i][j].GetY();
}
Board::Board(int pSize, int pX, int pY)
{
	size = pSize;
	left = pX;
	top = pY;
	pArr = new Point*[pSize];
	for (int i = 0; i < pSize; i++)
	{
		pArr[i] = new Point[pSize];
	}

}
Board::~Board()
{
	for (int i = 0; i < size; i++)
	{
		delete[] pArr[i];
	}
	delete[] pArr;
}
bool Board::isEmptyBoard(int** a, int n, int m) // kiểm tra xem bàn cờ đã có quân cờ nào chưa
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != 0)
				return false;
		}
	}
	return true;
}
void Board::resetData()// reset data với trường hợp không có dữ liệu, 
{
	if (size == 0)
		return;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			pArr[i][j].setX(4 * j + left + 2);
			pArr[i][j].setY(2 * i + top + 1);
			pArr[i][j].setCheck(0);// cho mọi ô cờ đều bằng 0
		}
	}
}
void Board::resetData(int** oldGame, int turn2)// reset data với trường hợp có bàn cờ đang chơi dỡ
{
	if (size == 0)
		return;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			pArr[i][j].setX(4 * j + left + 2);
			pArr[i][j].setY(2 * i + top + 1);
			pArr[i][j].setCheck(oldGame[i][j]);// truyền vào mỗi ô cờ theo dữ liệu trong file
		}
	}
}
void Board::drawBoard()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	char kitu0 = 32;																												//
	char kitu1 = 179, kitu2 = 180, kitu3 = 191, kitu4 = 192;											// các kí tự cần để in ra bàn cờ caro
	char kitu5 = 193, kitu5_5 = 194, kitu6 = 195, kitu7 = 196, kitu8 = 197;				//
	char kitu9 = 217, kitu10 = 218;																					//
	if (pArr == NULL) return;
	// cột dọc đầu tiên ok
	Common::gotoXY(left, top);
	cout << kitu10;// in ra góc trái trên
	cout << kitu7;
	cout << kitu7;
	cout << kitu7;
	Common::gotoXY(left, top + 1);
	cout << kitu1;
	Common::gotoXY(left, top + 2 * size - 1);
	cout << kitu1;
	Common::gotoXY(left, top + 2 * size);
	cout << kitu4;// in ra góc dưới trái
	cout << kitu7;
	cout << kitu7;
	cout << kitu7;
	// in ra góc dưới trái
	Common::gotoXY(left + 4 * size, top);
	cout << kitu3;
	Common::gotoXY(left + 4 * size, top + 1);
	cout << kitu1;
	for (int i = 1; i < size; i++)
	{
		Common::gotoXY(left + 4 * size, top + 2 * i);
		cout << kitu2;
		Common::gotoXY(left + 4 * size, top + 2 * i + 1);
		cout << kitu1;
	}
	// in ra góc phải dưới
	Common::gotoXY(left + 4 * size, top + 2 * size);
	cout << kitu9;
	// hàng ngang đầu tiên ok
	for (int i = 1; i < size; i++)
	{
		Common::gotoXY(left + 4 * i, top);
		cout << kitu5_5 << kitu7 << kitu7 << kitu7;
		Common::gotoXY(left + 4 * i, top + 1);
		cout << kitu1;
	}
	// hàng ngang cuối cùng 0k
	for (int i = 1; i < size; i++)
	{
		Common::gotoXY(left + 4 * i, top + 2 * size);
		cout << kitu5 << kitu7 << kitu7 << kitu7;
	}
	for (int i = 1; i < size; i++)
	{
		Common::gotoXY(left, top + 2 * i);
		cout << kitu6 << kitu7 << kitu7 << kitu7;
		Common::gotoXY(left, top + 2 * i + 1);
		cout << kitu1;
	}
	Common::gotoXY(left, top + 2 * size);
	cout << kitu4;

	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			Common::gotoXY(left + 4 * i, top + 2 * j);
			cout << kitu8;
			cout << kitu7;
			cout << kitu7;
			cout << kitu7;
			Common::gotoXY(left + 4 * i, top + 2 * j + 1);
			cout << kitu1;
		}
	}
	// vẽ khung
	char a = 176;
	for (int i = 0; i < 2 * size + top + 3; i++)
	{
		Common::gotoXY(4 * size + left + 8, i);
		cout << a;
	}
	for (int i = 0; i < 148; i++)
	{
		Common::gotoXY(i, 2 * size + left + 2);
		cout << a;
	}
	//////
	Common::gotoXY(pArr[0][0].GetX(), pArr[0][0].GetY());// đưa con trỏ về ô đầu

														 ///

}
void Board::writeName(int n1, int n2 )
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	Common::gotoXY(4 * size + left + 30, 2);
	cout << "P L A Y E R  1";
	Common::gotoXY(4 * size + left + 31, 4);
	cout << "X :  " << n1;
	Common::gotoXY(4 * size + left + 30, 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "P L A Y E R  2";
	Common::gotoXY(4 * size + left + 31, 9);
	cout << "O :  " << n2;
	char a = 176;
	Common::gotoXY(4 * size + left + 9, 15);
	for (int i = 4 * size + left + 9; i < 148; i++)
	{
		cout << a;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	Common::gotoXY(4 * size + left + 11, 25);
	cout << "Press I to go to Top\n";
	Common::gotoXY(4 * size + left + 11, 26);
	cout << "Press J to go to Left\n";
	Common::gotoXY(4 * size + left + 11, 27);
	cout << "Press K to go to Down\n";
	Common::gotoXY(4 * size + left + 11, 28);
	cout << "Press L to go to Right";
	Common::gotoXY(4 * size + left + 11, 29);
	cout << "Press ESC return to MENU";
	Common::gotoXY(pArr[0][0].GetX(), pArr[0][0].GetY());
}
int Board::CheckBoard(int pX, int pY, bool pTurn)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (pArr[i][j].GetX() == pX && pArr[i][j].GetY() == pY &&pArr[i][j].GetCheck() == 0)
			{
				if (pTurn)
					pArr[i][j].setCheck(-1);
				else
					pArr[i][j].setCheck(1);
				return pArr[i][j].GetCheck();
			}
		}
	}
	return 0;
}
int Board::TestBoard(int x, int y)// x,y là tọa độ console hiện tại của dấu nháy chuột// kiểm tra thắng thua
{
	// kiểm tra đã kín bàn cờ chưa
	int kt = 0;
	for (int i = 0; i < size; i++)// i, j tọa độ console 
	{
		for (int j = 0; j < size; j++)
		{
			if (pArr[i][j].GetCheck() != 0)
			{
				kt = 1;
				break;
			}
		}
		if (kt == 1)
			break;
	}
	if (kt == 0)
		return 0;
	// kiểm tra trục thẳng đứng
	int x2 = (y - top - 1) / 2; int y2 = (x - left - 2) / 4; int dem = -1;
	int CheckWin = pArr[x2][y2].GetCheck();
	while (pArr[x2][y2].GetCheck() == CheckWin)
	{
		dem++;
		if (x2 < size - 1)
		{
			x2++;
		}
		else
			break;
	}
	x2 = (y - top - 1) / 2; y2 = (x - left - 2) / 4;
	while (pArr[x2][y2].GetCheck() == CheckWin)
	{
		dem++;
		if (x2 >0)
		{
			x2--;
		}
		else
			break;
	}
	if (dem >= 5)
	{

		return CheckWin;
	}
	// dọc trục nằm ngang
	x2 = (y - top - 1) / 2; y2 = (x - left - 2) / 4; dem = -1;
	while (pArr[x2][y2].GetCheck() == CheckWin)
	{
		dem++;
		if (y2<size - 1)
		{
			y2++;
		}
		else
			break;
	}
	x2 = (y - top - 1) / 2; y2 = (x - left - 2) / 4;
	while (pArr[x2][y2].GetCheck() == CheckWin)
	{
		dem++;
		if (y2>0)
		{
			y2--;
		}
		else
			break;
	}
	if (dem >= 5)
		return CheckWin;
	// đường chéo 1
	x2 = (y - top - 1) / 2; y2 = (x - left - 2) / 4; dem = -1;
	while (pArr[x2][y2].GetCheck() == CheckWin)
	{
		dem++;
		if (y2 < size - 1 && x2>0)
		{
			y2++; x2--;
		}
		else
			break;
	}
	x2 = (y - top - 1) / 2; y2 = (x - left - 2) / 4;
	while (pArr[x2][y2].GetCheck() == CheckWin)
	{
		dem++;
		if (y2 > 0 && x2 < size - 1)
		{
			y2--; x2++;
		}
		else
			break;
	}
	if (dem >= 5)
		return CheckWin;
	// đường chéo 2
	x2 = (y - top - 1) / 2; y2 = (x - left - 2) / 4; dem = -1;
	while (pArr[x2][y2].GetCheck() == CheckWin)
	{
		dem++;
		if (y2 <size - 1 && x2<size - 1)
		{
			y2++; x2++;
		}
		else
			break;
	}
	x2 = (y - top - 1) / 2; y2 = (x - left - 2) / 4;
	while (pArr[x2][y2].GetCheck() == CheckWin)
	{
		dem++;
		if ((y2 > 0) && (x2 > 0))
		{
			y2--; x2--;
		}
		else
			break;
	}
	if (dem >= 5)
		return CheckWin;
	return 2;
}