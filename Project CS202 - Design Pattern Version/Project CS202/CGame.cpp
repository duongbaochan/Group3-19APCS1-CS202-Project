#include "CGame.h"


void Menu(CGame& x)
{
	//Credits section
	GotoXY(12, 1);
	TextColor(3);
	cout << "============================";
	GotoXY(12, 2);
	cout << "Members - Who has contributed to this project:";
	GotoXY(12, 3);
	TextColor(3);
	cout << "============================";
	TextColor(15);

	GotoXY(12, 5);
	cout << "Nguyen Minh Thu - 18125146";
	GotoXY(12, 6);
	cout << "Mai Thi Cam Van - 19125130";
	GotoXY(12, 7);
	cout << "Duong Bao Chan - 19125080";
	GotoXY(12, 8);
	cout << "Pham Dang Quang Vinh - 19125132";
	GotoXY(12, 9);
	cout << "Dinh Duy Phuoc - 19125115";
	TextColor(4);
	GotoXY(12, 11);
	cout << "Group 3 - 19CTT1 - CS202 Final Project";

	//Tutorial
	GotoXY(12, 14);
	TextColor(9);
	cout << "============================";
	GotoXY(12, 15);
	cout << "=       Tutorial:          =";
	GotoXY(12, 16);
	cout << "============================";
	GotoXY(12, 18);
	TextColor(10);
	cout << "You are put into an endless highway \n            with full of different obstacles. \n            Your only objective is to pass the road\n            safely without touching any obstacle,\n            otherwise you lose. ";
	GotoXY(12, 24);
	cout << "Break-a-leg!";

	//Menu section
	int width = 960, height = 540; // Size of menu

	setConsoleSize(width, height); // Set console size function, implemented in CGame.h

	GotoXY(60, 9);
	TextColor(6);
	cout << "        C R O S S Y  R O A D" << endl;
	GotoXY(60, 11);
	cout << "----------------MENU---------------" << endl;
	GotoXY(60, 12);
	cout << "|          1. New Game.           |" << endl;
	GotoXY(60, 13);
	cout << "|          2. Load Game.          |" << endl;
	GotoXY(60, 14);
	cout << "|          3. Settings.           |" << endl;
	GotoXY(60, 15);
	cout << "|          0. Exit.               |" << endl;
	GotoXY(60, 16);
	cout << endl;
	GotoXY(60, 17);
	cout << "Enter our option: ";

	int n; cin >> n;

	try {
		if (cin.fail())
			throw n;
	}

	catch (int n) {
		GotoXY(60, 19);
		cout << "Exception caught from input (Invalid input format). Exiting...\n";
		exit(0);
	}

	try {
		if (n == 1)
		{
			int level = 5;
			x.setGame(level, 1, 100, 0, 50, 0);
			//x.startGame(level);
			return;
		}
		else if (n == 2)
		{
			x.loadGame();
			int level = x.getLevel();
			//x.setGame(level, 1, 100, x.getScore(), x.getXPeople(), x.getYPeople());
			return;
		}
		else if (n == 3)
		{
			system("CLS");
			cout << "Settings 1." << endl;
			cout << "Settings 2." << endl;
			cout << "Settings 3." << endl;
		}
		else if (n == 0) return;
		else throw n;
	}

	catch (int n) {
		GotoXY(60, 19);
		cout << "Exception caught from input (Input option is not available). Exiting...\n";
		exit(0);
	}
}

void setConsoleSize(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, width, height, TRUE);
}

int CGame::getScore()
{
	return score;
}

int CGame::getLevel()
{
	return size;
}

CPeople CGame::getPeople()
{
	return cn;
}

CGame::CGame(){
	size = 0;
	score = 0;
	width = 0;
}
/*void CGame::setGame()
{
	stop = 0;
	//srand(time(NULL));
	
	FixConsoleWindow();

	unsigned short k = rand() % typeOfObj;
	for (int i = 1; i <= size; i++)
	{
		CTruck objT(0 - i * _width / size + rand() % 7, k * 8 + 2);
		CCar objC(0 - i * _width / size + 40 + rand() % 7, (k + 1) % typeOfObj * 8 + 2);
		CBird objB(0 - i * _width / size - 10 + rand() % 15, (k + 2) % typeOfObj * 8 + 2);
		CDinausor objD(0 - i * _width / size + 15 + rand() % 15, (k + 3) % typeOfObj * 8 + 2);

		arrTr.push_back(objT);
		arrC.push_back(objC);
		arrB.push_back(objB);
		arrD.push_back(objD);
	}
	CTrafficLight objL(_width, k * 8 + 2);
	arrL.push_back(objL);
	CTrafficLight objL1(_width, (k + 1) % typeOfObj * 8 + 2);
	arrL.push_back(objL1);

	cn.setXY(xPeople, yPeople);


	for (int i = 0; i < 2; i++)
		speed.push_back(_speed);
	x.setGame(level, 1, 100, x.getScore(), x.getXPeople(), x.getYPeople());
}*/

void CGame::setGame(int _size, int _speed, int _width, int _score, int xPeople, int yPeople) // x: level (higher - harder) 1 2 3 4 
{
	//x(1, 1, 100, 0, 50, 0)
	stop = 0;
	//srand(time(NULL));
	score = _score;
	size = _size;
	width = _width;
	FixConsoleWindow();
	
	unsigned short k = rand() % typeOfObj;
	vector <CPoint> x;

	for (int i = 1; i <= size; i++)
	{
		/*CTruck objT(0 - i * _width / size + rand()%7, k * 8 + 2);
		CCar objC(0 - i * _width / size + 40 + rand() % 7, (k + 1) % typeOfObj * 8 + 2);
		CBird objB(0 - i * _width / size -10 + rand() % 15, (k + 2) % typeOfObj * 8 + 2);
		CDinausor objD(0 - i * _width / size +  15 + rand() % 15, (k + 3) % typeOfObj * 8 + 2);
		cout << &objT << endl;
		arrTr.push_back(objT);
		arrC.push_back(objC);
		arrB.push_back(objB);
		arrD.push_back(objD);

		arrTr.push_back(CTruck(0 - i * _width / size + 40 + rand() % 7, (k + 1) % typeOfObj * 8 + 2));
		arrC.push_back(CCar(0 - i * _width / size + 40 + rand() % 7, (k + 1) % typeOfObj * 8 + 2));
		arrB.push_back(CBird(0 - i * _width / size - 10 + rand() % 15, (k + 2) % typeOfObj * 8 + 2));
		arrD.push_back(CDinausor(0 - i * _width / size + 15 + rand() % 15, (k + 3) % typeOfObj * 8 + 2));
		*/

		arrTr.addObject(0 - i * _width / size  + rand() % 7, k * 8 + 2);
		arrC.addObject(0 - i * _width / size + 40  + rand() % 7, (k + 1) % typeOfObj * 8 + 2);
		arrB.addObject(0 - i * _width / size - 10 + rand() % 15, (k + 2) % typeOfObj * 8 + 2);
		arrD.addObject(0 - i * _width / size + 15  + rand() % 15, (k + 3) % typeOfObj * 8 + 2);

	}
	CTrafficLight objL(_width, k * 8 + 2);
	arrL.push_back(objL);
	CTrafficLight objL1(_width, (k + 1) % 4 * 8 + 2);
	arrL.push_back(objL1);

	cn.setXY(xPeople, yPeople);


	for (int i = 0; i < 2; i++)
		speed.push_back(_speed);
}

void CGame::drawGame(string line)
{
	// draw line
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


	//if (arrL[1].getColor() == 12)
		//Sleep(5);
	arrTr.display(0, speed[0]);
	arrTr.updatePos(width, speed[0]);
	arrTr.display(3, speed[0]);

	arrC.display(0, speed[0]);
	arrC.updatePos(width, speed[0]);
	arrC.display(5, speed[0]);

	arrB.display(0, 1);
	arrB.updatePos(width, speed[1]);
	arrB.display(7, 1);

	arrD.display(0, 1);
	arrD.updatePos(width, speed[1]);
	arrD.display(9, 1);

	/*for (int i = 0; i < size; i++)
	{
		arrTr[i].display(0, speed[0]);
		arrTr[i].updatePos(width, speed[0]);
		arrTr[i].display(3, speed[0]);

		arrC[i].display(0, speed[0]);
		arrC[i].updatePos(width, speed[0]);
		arrC[i].display(5, speed[0]);

		arrB[i].display(0, 1);
		arrB[i].updatePos(width, speed[1]);
		arrB[i].display(7, 1);

		arrD[i].display(0, 1);
		arrD[i].updatePos(width, speed[1]);
		arrD[i].display(9, 1);
	}*/
	for (int i = 0; i < 2; ++i)
		arrL[i].draw();
}
void CGame::updatePosPeople(char& current, bool flag)
{
	GotoXY(100, 0);
	cout << "Score: " << score;
	GotoXY(100, 1);
	cout << "Level: " << (score / 40) + 1;


	/*if (cn.mY == 7 || cn.mY == 14 || cn.mY == 22 || cn.mY == 29)
	{
		score += 10;
		cn.Down();
	}*/

	if (flag == 1)
		cn.setXY(width/2, 0);

	cn.gotoXYPeople();
    cn.draw();

	if (current == 'A' || current == 'D' || current == 'W' || current == 'S'|| current == 'L') {
		cn.erase();
		switch (current) {
		case 'A':
			cn.Left();
			break;
		case 'D':
			cn.Right();
			break;
		case 'W':
			cn.Up();
			break;
		case 'S':
			cn.Down();
			break;
		case 'L':
			stop = 1;
			saveGame();
			break;
		}
	}
	/*
		cn.changeXY(-1,0);
	if (current == 'd')
		cn.changeXY(1, 0);
	if (current == 'w')
		cn.changeXY(0, -1);
	if (current == 's')
		cn.changeXY(0, 1);
	*/
	if (current == ' ')
		stop = true;

	current = '0';
}

void CGame::startGame(int &level, char& current)
{
	system("cls");
	string line = "";
	for (int i = 0; i < 100; i++)
		line += "*";

	unsigned short k = rand() % 5 + 5; //time period
	time_t t = time(0);
	tm* Check = localtime(&t);
	int tmp = Check->tm_sec;
	while (!stop)
	{
		if (cn.isFinish() == 0)
		{
			system("cls");
			cout << "Game over!!!" << endl;
			return;
		}
		drawGame(line);
		updatePosPeople(current, 0);
		pauseGame(NULL);
		runningGame(level, current);
		Sleep(400 / (score + 10));

		t = time(0);
		Check = localtime(&t);
		if ((Check->tm_sec - tmp) == k) {
			for (int i = 0; i < 2; ++i)
				arrL[i].changeColor(arrL[i].getColor(), speed[0], speed[1]);
			tmp = Check->tm_sec;
		}
	}
}
void CGame::runningGame(int level, char& current)
{
	for (int i = 0; i < size; i++)
	{
		if (cn.isImpact(arrC) || cn.isImpact(arrD) || cn.isImpact(arrB) || cn.isImpact(arrTr))
		{
			cn.setmState(0);
			return;
		}
	}
	if (cn.isFinishTurn(level + 24))
		updatePosPeople(current, 1);
}
CGame::~CGame()
{
	score = 0;
	stop = 0;
	size = 0;
}
void CGame::resetGame()
{
	this->~CGame();
}
void CGame::exitGame(HANDLE t)
{
	TerminateThread(t, 0);
	system("cls");
	cout << "Your score: " << score << endl;
	exit(0);
}
void CGame::pauseGame(HANDLE t)
{
	SuspendThread(t);
}
void CGame::resumeGame(HANDLE t)
{
	ResumeThread(t);
}
void CGame::loadGame()
{
	//cout << "Enter your path: ";
	//string s;
	//getline(cin, s);
	ifstream f;
	f.open("Game1.txt");
	if (!f.is_open())
		cout << "Can not open file." << endl;
	else
	{
		CPoint pos;
		bool tmpState;
		f >> size >> score >> stop >> width >> pos.mX >> pos.mY >> tmpState;
		cn.setmState(tmpState);
		cn.setXY(pos.mX, pos.mY);
	}
	f.close();
	//this->startGame(size);
}
void CGame::saveGame()
{
	//cout << "Enter your location: ";
	//string s;
	//getline(cin, s);
	ofstream f;
	f.open("Game1.txt");
	if (!f.is_open())
		cout << "Can not open file." << endl;
	else
	{
		f << size << " " << score << " " << stop << " " << width << " ";
		cn.outputFile(f);
	} 
	f.close();
}
/*
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
*/
