#include "CGame.h"

int main()
{
	GotoXY(-4, 2);
	cout << "hi";
	CGame x(1,2,200);
	x.startGame(5);
	system("pause");
	return 0;
}