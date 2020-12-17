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
			CGame x(1, 2, 100, 0, 50, 0);
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
	width = 0;
}

CGame::CGame(int _size, int _speed, int _width, int _score, int xPeople, int yPeople) // x: level (higher - harder) 1 2 3 4 
{
	stop = 0;
	//srand(time(NULL));
	score = _score;
	size = _size;
	width = _width;
	FixConsoleWindow();
	unsigned short k = rand() % 4;
	for (int i = 1; i <= size; i++)
	{
		CTruck* objT = new CTruck(0 - i * _width / size, k * 8 + 2);
		CCar* objC = new CCar(0 - i * _width / size + 40, (k + 1) % 4 * 8 + 2);
		CBird* objB = new CBird(0 - i * _width / size + 25, (k + 2) % 4 * 8 + 2);
		CDinausor* objD = new CDinausor(0 - i * _width / size + 15, (k + 3) % 4 * 8 + 2);
		
		arrTr.push_back(objT);
		arrC.push_back(objC);
		arrB.push_back(objB);
		arrD.push_back(objD);
	}
	CTrafficLight objL(_width, k * 8 + 2);
	arrL.push_back(objL);
	CTrafficLight objL1(_width, (k + 1) % 4 * 8 + 2);
	arrL.push_back(objL1);



	for (int i = 0; i < 2; i++)
		speed.push_back(_speed);
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
	cn.GotoXY();
	cout << "N:";
	if (flag == 1)
	{
		cn.setXY(100 / 2, 0);
	}
	if (_kbhit())
	{
		char current = _getch();
		if (current == 'a')
			cn.changeXY(-1,0);
		if (current == 'd')
			cn.changeXY(1, 0);
		if (current == 'w')
			cn.changeXY(0, -1);
		if (current == 's')
			cn.changeXY(0, 1);
		if (current == ' ')
			stop = true;
	}
}
void CGame::updatePosVehicle()
{
	for (int i = 0; i < size; i++)
	{
		arrC[i]->updatePosVehicle(width, speed[0]);
		arrTr[i]->updatePosVehicle(width, speed[0]);
	}
}
void CGame::updatePosAnimal()
{
	for (int i = 0; i < size; i++)
	{
		arrB[i]->updatePosAnimal(width, speed[1]);
		arrD[i]->updatePosAnimal(width, speed[1]);
	}
}
void CGame::startGame(int level)
{
	system("cls");
	string line = "";
	for (int i = 0; i < 100; i++)
		line += "*";


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
	while (!stop)
	{
		if (cn.isFinish() == 0)
		{
			system("pause");
			return;
		}
		drawGame();
		updatePosPeople();
		pauseGame();
		runningGame(level);

		t = time(0);
		Check = localtime(&t);
		if ((Check->tm_sec - tmp) == k) {
			for (int i = 0; i < 2; ++i) {
				arrL[i].changeColor(arrL[i].getColor(), speed[0], speed[1]);
			}
			tmp = Check->tm_sec;
		}
		updatePosVehicle();
		updatePosAnimal();
	}
}
void CGame::runningGame(int level)
{
	for (int i = 0; i < size; i++)
	{
		if (cn.isImpact(arrC[i]) || cn.isImpact(arrD[i]) || cn.isImpact(arrB[i]) || cn.isImpact(arrTr[i]))
		{
			cn.Finish();
			return;
		}
	}
	if (cn.isFinishTurn(level+18))
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
		f >> size >> score >> stop >> width;// >> mX >> mY >> mState;
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
		f << size << " " << score << " " << stop << " " << width;// << " " << cn.mX << " " << mY << " " << mState;
	}
	f.close();
}
void CGame::pauseGame()
{
	bool pause_call = false;
	if (kbhit()) {
		if (GetAsyncKeyState(0x50) == true && pause_call == false) {
			pause_call = true;
			Sleep(700);

			while (!GetAsyncKeyState(0x50))
				Sleep(1);

			pause_call = false;

		}
	}
}

