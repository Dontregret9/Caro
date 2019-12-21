#include<fstream>
#include"PlayGame.h"
void PlayGame::Menu(int kichthuoc)
{
	system("cls");
	Common::resizeConsole(1100, 800);// chỉnh lại kích thước console để thể hiện bàn cờ dễ hơn
	Common::fixConsoleWindow();// cố định console
	int tieptuc = 1;
	while (tieptuc)
	{
		system("cls");
		char kitu = 175;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		cout << " \t\t\t\t\t  ___    ___  ___  ___  ____      ___  ___  ____    ___\n";
		cout << "\t\t\t\t\t // \\\\  // \\\\ ||\\\\//|| ||        //   // \\\\ || \\\\  // \\\\\n";
		cout << "\t\t\t\t\t((  ___ ||=|| || \\/ || ||==     ((    ||=|| ||_// ((   ))\n";
		cout << "\t\t\t\t\t \\\\_ || || || || || || ||___     \\\\__ || || || \\\\  \\\\_//\n\n\n";


		cout << "                                         " << kitu << kitu << " 1. NEW GAME\n";
		cout << "                                         " << kitu << kitu << " 2. LOAD GAME\n";
		cout << "                                         " << kitu << kitu << " 3. SETTINGS\n";
		cout << "                                         " << kitu << kitu << " 4. Exit\n";
		int select;
		cout << "Enter you chosen:\n";
		cin >> select;
		switch (select)
		{
		case 1:
			PlayNow(kichthuoc);
			break;
		case 2:
			LoadGame(kichthuoc);
			break;
		case 3:
			Setting(kichthuoc);
			break;
		case 4:
			tieptuc = 0;
			system("cls");
			for (int i = 1; i < 10; i++)
			{
				cout << "\n\n\n\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
				cout << "\t\t\t\t  ___    ___     ___   ____   ____  _  _  ____\n";
				cout << "\t\t\t\t // \\\\  // \\\\   // \\\\  || \\\\  || )) \\\\// ||\n";
				cout << "\t\t\t\t(( ___ ((   )) ((   )) ||  )) | =)   )/  || ==\n";
				cout << "\t\t\t\t \\\\_||  \\\\_//   \\\\_//  ||_//  ||_)) //   ||___\n";

				cout << "\t\t\t\t__   ____   ____  _  _   ___   __ __     ___    ___   ___  __ __   __    __\n";
				cout << "\t\t\t\t((\\ ||     ||     \\\\//  // \\\\  || ||    // \\\\  // \\\\ // \\\\ || ||\\  ||    ||\n";
				cout << "\t\t\t\t \\\\ ||==   ||==    )/  ((   )) || ||    ||=|| (( ___ ||=|| || || \\\\||    ||\n";
				cout << "\t\t\t\t\\_))||___  ||___  //    \\\\_//  \\\\_//    || ||  \\\\_|| || || || ||  \\||    ..\n";
				Sleep(200);
				system("cls");
			}
			break;
		default:
			system("cls");
			cout << "Select a number again\n";
			Sleep(500);
		}
	}
}
void PlayGame::PlayNow(const int kichthuoc)// chơi game mới
{
	system("cls");
	Game g(20, 1, 1);
	g.startGame();
	while (g.isContinue())
	{
		g.waitKeyboard();
		if (g.getCommand() == 27)
			g.exitGame("lastgame", kichthuoc);
		else
		{
			switch (g.getCommand())
			{
			case 'J':
				g.moveLeft();
				break;

			case 'I':
				g.moveUp();
				break;

			case 'K':
				g.moveDown();
				break;
			case 'L':
				g.moveRight();
				break;
			case 13:
				if (g.processCheckBoard())
				{
					g.processFinish();
				}
				break;
			}
		}
	}
}
void PlayGame::LoadGame(const int kichthuoc)// chơi game đọc từ file, tải lại game đã chơi
{
	fstream file;
	file.open("lastgame", ios::in | ios::out);
	if (file.is_open())
	{
		Game g(kichthuoc, 1, 1);
		int** a = new int*[kichthuoc];                       //
		for (int i = 0; i < kichthuoc; i++)                  //		cấp phát cho mảng con trỏ
		{                                                                       //
			a[i] = new int[kichthuoc];                         //
		}
		int luot;
		file >> luot;                                                      // lấy giá trị lượt đi
		for (int i = 0; i < kichthuoc; i++)
		{
			for (int j = 0; j < kichthuoc; j++)
			{
				file >> a[i][j];                                         // xuất bàn cờ vào ma trận
			}
		}

		if (luot == 1)
		{
			luot = true;                                               //chuyển về kiểu bool
		}
		else
			luot = false;                                             // chuyển về kiểu bool
		bool temp = Board::isEmptyBoard(a, kichthuoc, kichthuoc);
		if (temp)
		{
			PlayNow(kichthuoc);
		}
		else
		{
			g.startGame(a, luot);
			g.setTurn(luot);                                        // cài đặt lại lượt đi
			while (g.isContinue())
			{
				g.waitKeyboard();
				if (g.getCommand() == 27)
					g.exitGame("lastgame", kichthuoc);
				else
				{
					switch (g.getCommand())
					{
					case 'J':
						g.moveLeft();
						break;
					case 'I':
						g.moveUp();
						break;

					case 'K':
						g.moveDown();
						break;
					case 'L':
						g.moveRight();
						break;
					case 13:
						if (g.processCheckBoard())
						{
							g.processFinish();
						}
						break;
					}
				}
			}
		}
		for (int i = 0; i < kichthuoc; i++)
		{
			delete a[i];
		}
		delete a;
		file.close();
	}
	else
	{
		system("cls");
		cout << "\n--------------------------------------------------------------------------oxo-----------------------------------------------------------------------\n";
		cout << "\n\n\n\n";
		cout << "\t\t\tSO SORRY!\n";
		cout << "\t\t\tDON'T HAVE A UNCOMPETE GAME\n";
		cout << "\t\t\tA new game will be start.........\n";
		cout << "\n\n\n\n";
		cout << "--------------------------------------------------------------------------oxo-----------------------------------------------------------------------\n";

		Sleep(3000);
		PlayNow(kichthuoc);                                         // nếu không có game nào được lưu thì chơi mới
		system("cls");
	}
}
void PlayGame::Setting(int kichthuoc)
{
	system("cls");
	int continue_ = 1;
	do
	{
		system("cls");
		char kitu = 175;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		cout << "\t\t\t\t\t__   ____ ______ ______ __ __  __   ___   __\n";
		cout << "\t\t\t\t\t((\\  ||   | || | | || | || ||\\ ||  // \\ (( \\\n";
		cout << "\t\t\t\t\t \\\\  ||==   ||     ||   || ||\\\\|| (( ___  \\\\\n";
		cout << "\t\t\t\t\t\\_)) ||___  ||     ||   || || \\|| \\\\_ || \\_))\n\n\n";
		cout << "                                         " << kitu << kitu << " 1. Play with Computer\n";
		cout << "                                         " << kitu << kitu << " 2. Two players\n";
		cout << "                                         " << kitu << kitu << " 3. Information\n";
		cout << "                                         " << kitu << kitu << " 4. To MENU\n";
		int selection;
		cout << "Enter your chose:\t";
		cin >> selection;
		switch (selection)
		{
		case 1: PlayWithComputer();
			break;
		case 2:TwoPlayer();
			break;
		case 3:Information();
			break;
		case 4: 
			break;
		}
		if (selection == 4)
			break;
		system("cls");
		cout << "Do you want to go to MENU or again?\n";
		cout << "Press 0 to go to MENU and other to see again\n ";
		cin >> continue_;
	} while (continue_);

}
void PlayGame::PlayWithComputer()
{
	system("cls");
	cout << "\t\t\t\t\t__   ____ ______ ______ __ __  __   ___   __\n";
	cout << "\t\t\t\t\t((\\  ||   | || | | || | || ||\\ ||  // \\ (( \\\n";
	cout << "\t\t\t\t\t \\\\  ||==   ||     ||   || ||\\\\|| (( ___  \\\\\n";
	cout << "\t\t\t\t\t\\_)) ||___  ||     ||   || || \\|| \\\\_ || \\_))\n\n\n";
	cout << "						This feature isn't complete. Please wait!";
	Sleep(4000);
}
void PlayGame::TwoPlayer()
{
	system("cls");
	cout << "\t\t\t\t\t__   ____ ______ ______ __ __  __   ___   __\n";
	cout << "\t\t\t\t\t((\\  ||   | || | | || | || ||\\ ||  // \\ (( \\\n";
	cout << "\t\t\t\t\t \\\\  ||==   ||     ||   || ||\\\\|| (( ___  \\\\\n";
	cout << "\t\t\t\t\t\\_)) ||___  ||     ||   || || \\|| \\\\_ || \\_))\n\n\n";	cout << "						You are playing in two player mode!\n";
	Sleep(4000);
}
void PlayGame::Information()
{
	system("cls");
	cout << "\t\t\t\t\t__   ____ ______ ______ __ __  __   ___   __\n";
	cout << "\t\t\t\t\t((\\  ||   | || | | || | || ||\\ ||  // \\ (( \\\n";
	cout << "\t\t\t\t\t \\\\  ||==   ||     ||   || ||\\\\|| (( ___  \\\\\n";
	cout << "\t\t\t\t\t\\_)) ||___  ||     ||   || || \\|| \\\\_ || \\_))\n\n\n";
	cout << "					Information of team:\n";
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "						Nhom 24 -lop 17CTT3\n";
	cout << "Giao vien huong dan: Truong Toan Thinh professor\n";
	cout << "Sinh vien thuc hien:\n";
	cout << "1. Le Duc Hoa					MSSV	1712449\n";
	cout << "2. Nguyen Van Hieu				MSSV	1712439\n";
	cout << "3. Nguyen Minh Hien				MSSV	1712425\n";
	cout << "4. Dao Khanh Duy				MSSV	1712380\n";
	Sleep(10000);
}