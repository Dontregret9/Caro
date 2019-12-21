#include"Common.h"
void Common::gotoXY(int pX, int pY)
{
	COORD	coord;
	coord.X = pX;
	coord.Y = pY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Common::fixConsoleWindow()// cố định màn hình console
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style &~(WS_MAXIMIZEBOX)&~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void Common::resizeConsole(int width, int height)// điều chỉnh màn hình console để hiển thị bàn cờ đẹp hơn
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}