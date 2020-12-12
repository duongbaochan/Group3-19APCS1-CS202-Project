#include "CGame.h"

void Menu()
{
	cout << "----------------MENU--------------" << endl;
	cout << "        WELCOME TO THE GAME       " << endl;
	cout << "1. New Game." << endl;
	cout << "2. Load Game." << endl;
	cout << "3. Settings." << endl;
	cout << "0. Exit." << endl;
	cout << "Enter our option: ";
	int n; cin >> n;
	while (n)
	{
		if (n == 1)
		{
			CGame x(1, 2, 100);
			x.startGame(5);
			break;
		}
		else if (n == 2)
		{
			CGame x;
			x.loadGame();
			break;
		}
		else if (n == 0) return;
		else
		{
			cout << "Please choose again...";
			cin >> n;
		}
	}
}
CGame::CGame(){
	size = 0;
	score = 0;
	stop = 0;
	width = 0;
}

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
		CTruck *objT = new CTruck(0 - i * w / size,k * 8 + 2);
		CCar *objC = new CCar(0 - i * w / size + 40, (k + 1) % 4 * 8 + 2);
		CBird *objB = new CBird(0 - i * w / size + 25, (k + 2) % 4 * 8 + 2);
		CDinausor *objD = new CDinausor(0 - i * w / size + 15, (k + 3) % 4 * 8 + 2);
		
		arrTr.push_back(objT);
		arrC.push_back(objC);
		arrB.push_back(objB);
		arrD.push_back(objD);
	}
	CTrafficLight objL(w, k * 8 + 2);
	arrL.push_back(objL);
	CTrafficLight objL1(w, (k + 1) % 4 * 8 + 2);
	arrL.push_back(objL1);
}

void CGame::drawGame()
{
	system("cls");
	string line = "*****************************************************************";
	/*for (int i = 0; i < width; i++) {
		line += "*";
	}*/
	GotoXY(0, 1);
	TextColor(12);
	cout << line;
	GotoXY(0, 9);
	cout << line;
	GotoXY(0, 16);
	cout << line;
	GotoXY(0, 24);
	cout << line;
	TextColor(15);
	for (int i = 0; i < size; i++)
	{
		arrTr[i]->draw();
		arrC[i]->draw();
		arrB[i]->draw();
		arrD[i]->draw();
	}
	for (int i = 0; i < 2; ++i) {
		arrL[i].draw();
	}

//	draw();
	//draw line

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
void CGame::updatePosVehicle(int speed)
{
	for (int i = 0; i < size; i++)
	{
		arrC[i]->updatePosVehicle(width, speed);
		arrTr[i]->updatePosVehicle(width, speed);
	}
}
void CGame::updatePosAnimal()
{
	for (int i = 0; i < size; i++)
	{
		arrB[i]->updatePosAnimal(width);
		arrD[i]->updatePosAnimal(width);
	}
}
void CGame::startGame(int level)
{
	system("cls");
	string line = "";
	for (int i = 0; i < width; i++) {
		line += "*";
	}
	GotoXY(0, 1);
	TextColor(12);
	cout << line;
	GotoXY(0, 9);
	cout << line;
	GotoXY(0, 16);
	cout << line;
	GotoXY(0, 24);
	cout << line;
	TextColor(15);
	

	unsigned short k = rand() % 5 + 5; //time period
	time_t t = time(0);
	tm* Check = localtime(&t);
	int tmp = Check->tm_sec;
	int speed = 1;
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

		t = time(0);
		Check = localtime(&t);
		if ((Check->tm_sec - tmp) == k) {
			for (int i = 0; i < 2; ++i) {
				arrL[i].changeColor(arrL[i].getColor(), speed);
			}
			tmp = Check->tm_sec;
		}
		updatePosVehicle(speed);
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
		GotoXY(0, 0);
		cout << "Score: " << score;
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
void CGame::loadGame()
{
	cout << "Enter your path: ";
	string s;
	getline(cin, s);
	ifstream f;
	f.open(s);
	if (!f.is_open())
		cout << "Can not open file." << endl;
	else
	{
		for (int i = 0; i <= size; ++i)
		{
			int m, n;
			f >> m >> n;
			CTruck* objT = new CTruck(m, n);
			f >> m >> n;
			CCar* objC = new CCar(m, n);
			f >> m >> n;
			CBird* objB = new CBird(m, n);
			f >> m >> n;
			CDinausor* objD = new CDinausor(m, n);

			arrTr.push_back(objT);
			arrC.push_back(objC);
			arrB.push_back(objB);
			arrD.push_back(objD);
		}
		f >> size >> score >> stop >> width >> mX >> mY >> mState;
	}
	f.close();
	this->startGame(5);
}
void CGame::saveGame()
{
	cout << "Enter your location: ";
	string s;
	getline(cin, s);
	ofstream f;
	f.open(s + "\\a.txt");
	if (!f.is_open())
		cout << "Can not open file." << endl;
	else
	{
		for (int i = 0; i <= size; ++i)
			f << arrTr[i]->getX() << " " << arrTr[i]->getY() << " " << arrC[i]->getX() << " " << arrC[i]->getY() << " " << arrB[i]->getX() << " " << arrB[i]->getY() << " " << arrD[i]->getX() << " " << arrD[i]->getY() << endl;
		f << size << " " << score << " " << stop << " " << width << " " << mX << " " << mY << " " << mState;
	}
	f.close();
}
void CGame::pauseGame(HANDLE)
{

}
void CGame::resumeGame(HANDLE)
{

}

