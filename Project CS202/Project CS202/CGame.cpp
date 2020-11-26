#include "CGame.h"

CGame::CGame(int x, int speed, int w): CPeople(w) // x: level (higher - harder) 1 2 3 4 
{
	//srand(time(NULL));
	size = x + 4;
	FixConsoleWindow();
	unsigned short k = rand() % 4;
	for (int i = 0; i < size; i++)
	{
		CTruck *objT = new CTruck(0 - i*(5-x),k);
		CCar *objC = new CCar(0 - i * (5 - x), (k+1)%4);
		CBird *objB = new CBird(0 - i * (5 - x), (k + 2) % 4);
		CDinausor *objD = new CDinausor(0 - i * (5 - x), (k + 3) % 4);

		arrTr.push_back(objT);
		arrC.push_back(objC);
		arrB.push_back(objB);
		arrD.push_back(objD);
	}
}

void CGame::drawGame()
{
	system("cls");
	for (int i = 0; i < size; i++)
	{
		arrTr[i]->draw();
		arrC[i]->draw();
		arrC[i]->draw();
		arrC[i]->draw();
	}
}
void CGame::updatePosPeople(char)
{

}
void CGame::updatePosVehicle()
{

}
void CGame::updatePosAnimal()
{

}