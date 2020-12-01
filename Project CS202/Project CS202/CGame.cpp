#include "CGame.h"

CGame::CGame(int x, int speed, int w): CPeople(w) // x: level (higher - harder) 1 2 3 4 
{
	stop = 0;
	//srand(time(NULL));
	size = x + 4;
	width = w;
	FixConsoleWindow();
	unsigned short k = rand() % 4;
	for (int i = 1; i <= size; i++)
	{
		CTruck *objT = new CTruck(0 - i * w / 5,k + 2);
		CCar *objC = new CCar(0 - i * w / 5 + 40, (k+1)%4 + 2 + 4);
		CBird *objB = new CBird(0 - i * w / 5 + 25, (k + 2) % 4 + 2 + 8);
		CDinausor *objD = new CDinausor(0 - i * w / 5 + 15, (k + 3) % 4 + 2 + 16);

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
		arrB[i]->draw();
		arrD[i]->draw();
	}
	draw();
	GotoXY(0, 0);
	cout << "Score: " << score << endl;

}
void CGame::updatePosPeople(bool flag=0)
{
	GotoXY(mX, mY);
	cout << "N:";
	if (flag == 1)
	{
		mX = 100 / 2;
		mY = 0;
	}
	if (_kbhit())
	{
		char current = _getch();
		if (current == 'a')
			mX--;
		if (current == 'd')
			mX++;
		if (current == 'w')
			mY--;
		if (current == 's')
			mY++;
		if (current == ' ')
			stop = true;
	}
}
void CGame::updatePosVehicle()
{
	for (int i = 0; i < size; i++)
	{
		arrC[i]->updatePosVehicle(width);
		arrTr[i]->updatePosVehicle(width);
	}
}
void CGame::updatePosAnimal()
{
	for (int i = 0; i < size; i++)
	{
		arrB[i]->updatePosVehicle(width);
		arrD[i]->updatePosVehicle(width);
	}
}
void CGame::startGame(int level)
{
	while (!stop)
	{
		if (mState == 0)
		{
			system("pause");
			return;
		}
		drawGame();
		updatePosPeople();
		runningGame(level);
		updatePosVehicle();
		updatePosAnimal();
	}
}
void CGame::runningGame(int level)
{
	for (int i = 0; i < size; i++)
	{
		if (isImpact(arrC[i]) || isImpact(arrD[i]) || isImpact(arrB[i]) || isImpact(arrTr[i]))
		{
			mState = 0;
			return;
		}
	}
	if (mY == level + 18)
	{
		score++;
		updatePosPeople(1);
	}
}
CGame::~CGame()
{
	for (int i = 0; i < size; i++)
	{
		delete arrD[i];
		delete arrB[i];
		delete arrTr[i];
		delete arrC[i];
	}
	score = 0;
	stop = 0;
	size = 0;
}
void CGame::resetGame()
{
	this->~CGame();
}
void CGame::exitGame(HANDLE)
{
	system("cls");
	cout << "Your score: " << score << endl;
}
void CGame::loadGame(ostream)
{

}
void CGame::saveGame(istream)
{

}
void CGame::pauseGame(HANDLE)
{

}
void CGame::resumeGame(HANDLE)
{

}