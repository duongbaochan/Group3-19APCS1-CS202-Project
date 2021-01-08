#include "CGame.h"
#include <Windows.h>

bool IS_RUNNING = true;
char MOVING;
CGame game;
int level = 5;

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
int main()
{
	int width = 1100, height = 618.75; // Set width for ingame console

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
	*/
	return 0;
}
       