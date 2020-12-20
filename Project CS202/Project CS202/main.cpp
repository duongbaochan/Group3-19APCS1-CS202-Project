#include "CGame.h"
#include <Windows.h>

//bool IS_RUNNINg = true;
//
//void exitGame(thread* t)
//{
//	system("cls");
//	IS_RUNNINg = false;
//	t->join();
//}
//
//void ThreadFunc1()
//{
//	while (IS_RUNNINg)
//	{
//		Menu();
//		system("pause");
//	}
//}

int main()
{

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
       