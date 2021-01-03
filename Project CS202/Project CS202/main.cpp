#include "CGame.h"
#include <Windows.h>

//bool IS_RUNNING = true;
//
//void exitGame(thread* t)
//{
//	system("cls");
//	IS_RUNNING = false;
//	t->join();
//}



void ThreadFunc1(CGame x)
{
	while (IS_RUNNING)
	{
		x.drawGame();
		system("pause");
	}
	
}

int main()
{
	//cout << "----------------MENU--------------" << endl;
	//cout << "        WELCOME TO THE GAME       " << endl;
	//cout << "1. New Game." << endl;
	//cout << "2. Load Game." << endl;
	//cout << "3. Settings." << endl;
	//cout << "0. Exit." << endl;
	//cout << "Enter our option: ";
	//int n; cin >> n;

	//while (true) {
	//	try {
	//		if (cin.fail())
	//			throw n;
	//	}

	//	catch (...) {
	//		cout << "Exception caught from input (Invalid input format). Exiting...\n";
	//	}

	//	try {
	//		if (n == 1)
	//		{
	//			int level = 10;
	//			CGame x(level, 1, 100, 0, 50, 0);
	//			x.startGame(level);
	//			//thread t1(ThreadFunc1);	
	//			//t1.join();
	//		}
	//		else if (n == 2)
	//		{
	//			CGame x;
	//			x.loadGame();
	//		}
	//		else if (n == 0) return 0;
	//		else throw n;
	//	}
	//	catch (int n) {
	//		cout << "Exception caught from input (Input option is not available). Exiting...\n";
	//	}
	//}





	Menu();
	system("pause");

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
       