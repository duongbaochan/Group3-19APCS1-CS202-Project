#include "CGame.h"
#include <Windows.h>

bool IS_RUNNING = true;
char MOVING;
CGame game;
int level = 3;

void ThreadFunc1()
{
	game.startGame(level, MOVING);
}
void ThreadFunc2()
{
	PlaySound(TEXT("Sounds/menu-soundtrack.wav"), NULL, SND_LOOP | SND_ASYNC);
} // Menu theme
void ThreadFunc3()
{
	PlaySound(TEXT("Sounds/ingame.wav"), NULL, SND_LOOP | SND_ASYNC);
} // Ingame theme
void ThreadGameOver()
{
	PlaySound(TEXT("Sounds/game-over.wav"), NULL, SND_LOOP | SND_ASYNC);
} // Menu theme
void preMain()
{
	thread t2(ThreadFunc2);

	Menu(game);

	thread t3(ThreadFunc3);

	thread t1(ThreadFunc1);
	//int temp;
	char temp;
	while (1)
	{
		if (_kbhit()) {
			temp = toupper(_getch());
			//temp = _getch();
			if (!game.getPeople().isDead())
			{
				if (temp == 27 || temp == 'L' || temp == 32)
				{
					game.exitGame(t1.native_handle());
					game.saveGame();
					preMain();
					return;
					//return 0;
					//main();
				}
				else if (temp == 'P')
				{
					game.pauseGame(t1.native_handle());
				}
				else
				{
					MOVING = temp;
					game.resumeGame(t1.native_handle());
				}
			}
			else // nguoi bi dung -> cho choi tiep hay khong
			{
				/*if (temp == 'Y')
					game.startGame(level, temp);
				else
				{
					//game.exitGame(t1.native_handle());
					preMain();
					return;
				}*/
			}
		}
	}

}

/*void ThreadGameOver()
{
	PlaySound(TEXT("Sounds/game-over.wav"), NULL, SND_LOOP | SND_ASYNC);
} // Menu theme
*/
void CGame::startGame(int& level, char& current)
{
	system("cls");
	string line = "";
	for (int i = 0; i < 100; i++)
		line += "*";

	unsigned short k = rand() % 5 + 3; //time period
	time_t t = time(0);
	tm* Check = localtime(&t);
	int tmp = Check->tm_sec;
	int speedTr = arrTr.getSpeed();
	while (!stop)
	{
		if (cn.isDead())
		{
			system("cls");
			thread over(ThreadGameOver);
			GotoXY(57, 11);
			cout << "---------------" << endl;
			GotoXY(57, 12);
			cout << "|  GAME OVER  |" << endl;
			GotoXY(57, 13);
			cout << "---------------" << endl;
			Sleep(1500);
			GotoXY(48, 15);
			cout << "Don't give up just yet..." << endl;
			GotoXY(48, 16);
			Sleep(1500);
			cout << "You'll make it better next time! Keep up!" << endl;
			GotoXY(58, 18);
			Sleep(1500);
			TextColor(6);
			cout << "Your score: " << score << endl;
			GotoXY(49, 19);
			TextColor(7);
			system("pause");
			system("CLS");

			exitGame(NULL);
			preMain();
			exit(0);
		}
		if ((level % 5 == 0))
		{
			//this->resetGame();
			setGame(level / 5 + 3, 2, 100, score, 50, 0);
			//startGame(level, current);
			//return;
		}
		drawGame(line, speedTr);
		updatePosPeople(current, 0);
		pauseGame(NULL);
		runningGame(level, current);
		Sleep(2000 / (level * 5));

		t = time(0);
		Check = localtime(&t);
		if (tmp > 50)
			tmp = 0;
		if ((Check->tm_sec - tmp) == k) {
			for (int i = 0; i < 2; ++i)
				arrL[i].changeColor(arrL[i].getColor(), speedTr, arrB.getSpeed());
			tmp = Check->tm_sec;
		}
	}
}

int main()
{
	int width = 1100, height = 650; // Set width for ingame console
	setConsoleSize(width, height); // Set console size function, implemented in CGame.h
	preMain();
	return 0;
}
/*int main()
{
	int width = 1100, height = 560; // Set width for ingame console
>>>>>>> Stashed changes

	thread t2(ThreadFunc2);

	Menu(game);
	setConsoleSize(width, height); // Set console size function, implemented in CGame.h

	thread t3(ThreadFunc3);

	thread t1(ThreadFunc1);
	//int temp;
	char temp;
	while (1)
	{
		if (_kbhit()) {
			temp = toupper(_getch());
			//temp = _getch();
			if (game.getPeople().isDead())
			{
				if (temp == 27)
				{
					game.exitGame(t1.native_handle());
					//return 0;
					main();
				}
				else if (temp == 'P')
				{
					game.pauseGame(t1.native_handle());
				}
				else
				{
					MOVING = temp;
					game.resumeGame(t1.native_handle());
				}
			}
			else // nguoi bi dung -> cho choi tiep hay khong
			{
				if (temp == 'Y')
					game.startGame(level, temp);
				else
				{
					game.exitGame(t1.native_handle());
					return 0;
				}
			}
		}
	}

	//thread t1(ThreadFunc1);
	//while (1)
	//{
	//	int temp = toupper(getch());
	//	if (temp == 27)
	//	{
	//		exitGame(&t1);
	//		return 0;
	//	}
	//}

	//Menu();
	//system("pause");

	/*
	time_t t = time(0);
	tm* Check = localtime(&t);
	cout << Check->tm_sec << endl;
	for (int i = 0; i < 2; ++i) {
		Sleep(2000);
	}
	t = time(0);
	Check = localtime(&t);
	cout << Check->tm_sec << endl;
	
	return 0;
}*/
       