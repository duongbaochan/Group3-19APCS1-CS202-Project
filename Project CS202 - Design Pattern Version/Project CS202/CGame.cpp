#include "CGame.h"

void Menu(CGame& x)
{
	//CGame game;
	//Credits section
	GotoXY(12, 1);
	TextColor(3);
	cout << "==============================================";
	GotoXY(12, 2);
	cout << "Members - Who has contributed to this project:";
	GotoXY(12, 3);
	TextColor(3);
	cout << "==============================================";
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
	cout << "=        Tutorial:         =";
	GotoXY(12, 16);
	cout << "============================";
	GotoXY(12, 18);
	TextColor(10);
	cout << "You are put into an endless highway \n            with full of different obstacles. \n            Your only objective is to pass the road\n            safely without touching any obstacles,\n            otherwise you lose. ";
	GotoXY(12, 24);
	cout << "Break-a-leg!";

	//Menu section
	int width = 1100, height = 650; // Size of menu

	setConsoleSize(width, height); // Set console size function, implemented in CGame.h

	int m = 2;

	GotoXY(65 + m, 9);
	TextColor(6);
	cout << "        C R O S S Y  R O A D" << endl;
	GotoXY(65 + m, 11);
	cout << "----------------MENU---------------" << endl;
	GotoXY(65 + m, 12);
	cout << "|          1. New Game.           |" << endl;
	GotoXY(65 + m, 13);
	cout << "|          2. Load Game.          |" << endl;
	GotoXY(65 + m, 14);
	cout << "|          3. Settings.           |" << endl;
	GotoXY(65 + m, 15);
	cout << "|          4. Credits.            |" << endl;
	GotoXY(65 + m, 16);
	cout << "|          0. Exit.               |" << endl;
	GotoXY(65 + m, 17);
	cout << "-----------------------------------" << endl;
	GotoXY(65 + m, 19);
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
			int level = 3;
			x.setGame(level, 2, 100, 0, 50, 0);
			//x.startGame(level);
			return;
		}
		else if (n == 2)
		{
			x.loadGame();
			//int level = x.getLevel();
			//x.setGame(level, 1, 100, x.getScore(), x.getXPeople(), x.getYPeople());
			return;
		}
		else if (n == 3)
		{
			system("CLS");
			cout << "Settings 1." << endl;
			cout << "Settings 2." << endl;
			cout << "Settings 3." << endl;
			system("pause");
			system("CLS");
			Menu(x);
		}
		else if (n == 4)
		{
			system("CLS");
			GotoXY(25, 10);
			TextColor(6);
			cout << "|---------------------------------------------------------------|\n";
			GotoXY(25, 11);
			cout << "|                          CREDITS:                             |\n";
			GotoXY(25, 12);
			cout << "|                                                               |\n";
			GotoXY(25, 13);
			cout << "|                        Soundtracks:                           |\n";
			GotoXY(25, 14);
			cout << "|               Undertale OST: 002 - Start Menu                 |\n";
			GotoXY(25, 15);
			cout << "|              Undertale OST: 042 - Thundersnail                |\n";
			GotoXY(25, 16);
			cout << "|                                                               |\n";
			GotoXY(25, 17);
			cout << "|---------------------------------------------------------------|\n";
			system("pause");
			system("CLS");
			Menu(x);
		}
		else if (n == 0) {
			cout << endl << endl << endl;
			exit(0);
		}
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
void CGame::setGame(int _size, int _speed, int _width, int _score, int xPeople, int yPeople) // x: level (higher - harder) 1 2 3 4 
{
	resetGame();
	//x(1, 1, 100, 0, 50, 0)
	stop = 0;
	//srand(time(NULL));
	score = _score;
	size = _size;
	width = _width;
	FixConsoleWindow();
	
	unsigned short k = rand() % typeOfObj;

	int m = 4;

	for (int i = 1; i <= size; i++)
	{
		arrTr.addObject(0 - i * _width / size  + rand() % 7, k * 8 + 2 + m, _speed);
		arrC.addObject(0 - i * _width / size + 40  + rand() % 7, (k + 1) % typeOfObj * 8 + 2 + m, _speed);
		arrB.addObject(0 - i * _width / size - 10 + rand() % 15, (k + 2) % typeOfObj * 8 + 2 + m, _speed);
		arrD.addObject(0 - i * _width / size + 15  + rand() % 15, (k + 3) % typeOfObj * 8 + 2 + m, _speed);

	}
	arrL.push_back(CTrafficLight(_width, k * 8 + 2 + m));
	arrL.push_back(CTrafficLight(_width, (k + 1) % typeOfObj * 8 + 2 + m));

	cn.setXY(xPeople, yPeople);
}

void CGame::drawGame(string line, int speedTr)
{

	// draw line
	int m = 4;
	GotoXY(0, 1 + m);
	TextColor(12);
	cout << line;
	cn.draw();
	GotoXY(0, 9 + m);
	TextColor(12);
	cout << line;
	cn.draw();
	GotoXY(0, 16 + m);
	TextColor(12);
	cout << line;
	cn.draw();
	GotoXY(0, 24 + m);
	TextColor(12);
	cout << line;
	cn.draw();
	TextColor(15);

	/*arrTr.display(0, speed[0]);
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
	arrD.display(9, 1);*/
	arrTr.updatePosandDisp(width, speedTr, 3, 1);
	arrC.updatePosandDisp(width, speedTr, 5, 1);
	arrB.updatePosandDisp(width, arrB.getSpeed(), 7, 1);
	arrD.updatePosandDisp(width, arrD.getSpeed(), 9, 1);


	for (int i = 0; i < 2; ++i)
		arrL[i].draw();
}
void CGame::updatePosPeople(char& current, bool flag)
{
	int m = 7;
	int n = 4;
	GotoXY(99 + m, 3);
	TextColor(2);
	cout << "|=====================|";
	GotoXY(101 + m, 4);
	TextColor(9);
	cout << "C R O S S Y R O A D";
	GotoXY(106 + m, 5);
	TextColor(6);
	cout << "Score: " << score;
	GotoXY(106 + m, 6);
	cout << "Level: " << (score / 50) + 1;
	TextColor(2);
	GotoXY(99 + m, 7);
	cout << "|=====================|";

	//Game tutorial
	GotoXY(99 + m, 27);
	TextColor(9);
	cout << "-----------------------";
	GotoXY(99 + m, 28);
	cout << "|   ";
	TextColor(2);
	cout << "T U T O R I A L";
	TextColor(9);
	cout << "   | ";
	GotoXY(99 + m, 29);
	TextColor(9);
	cout << "-----------------------";
	GotoXY(105 + m, 30);
	TextColor(6);
	cout << "Save game: L";
	GotoXY(104 + m, 31);
	cout << "Pause game: P";
	GotoXY(105 + m, 32);
	cout << "Resume: R";
	GotoXY(105 + m, 33);
	cout << "Move: AWSD";


	/*if (cn.mY == 7 || cn.mY == 14 || cn.mY == 22 || cn.mY == 29)
	{
		score += 10;
		cn.Down();
	}*/

	if (flag == 1)
		cn.setXY(width / 2, 0);


	if (current == 'A' || current == 'D' || current == 'W' || current == 'S') {
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
		}
	}
	cn.draw();
	if (current == ' ')
		stop = true;

	current = '0';
}

/*void CGame::startGame(int &level, char& current)
{
	system("cls");
	string line = "";
	for (int i = 0; i < 100; i++)
		line += "*";

	unsigned short k = rand() % 5 + 3; //time period
	time_t t = time(0);
	tm* Check = localtime(&t);
	int tmp = Check->tm_sec;
	while (!stop)
	{
		if (cn.isFinish() == 0)
		{
			system("cls");
			thread over(ThreadGameOver);
			GotoXY(57, 11);
			cout << "---------------" << endl;
			GotoXY(57, 12);
			cout << "|  GAME OVER  |" << endl;
			GotoXY(57, 13);
			cout << "---------------" << endl;
			Sleep(2000);
			GotoXY(48, 15);
			cout << "Don't give up just yet..." << endl;
			GotoXY(48, 16);
			Sleep(2000);
			cout << "You'll make it better next time! Keep up!" << endl;
			GotoXY(58, 18);
			Sleep(2000);
			TextColor(6);
			cout << "Your score: " << score << endl;
			GotoXY(49, 19);
			TextColor(7);
			system("pause");
			system("CLS");

			exitGame(NULL);
			Menu(*this);
			//setGame(3, 2, 100, 0, 50, 0);
			//level = 0;
			//startGame(level, current);
			return;
		}
		drawGame(line);
		updatePosPeople(current, 0);
		pauseGame(NULL);
		runningGame(level, current);
		Sleep(2000 / (level*5));

		/*if (level % 5 == 0)
		{
			this->resetGame();
			setGame(level/5 + 3 , 2, 100, score, 50, 0);
			startGame(level, current);
			return;
		}
		t = time(0);
		Check = localtime(&t);
		if (tmp > 56)
			tmp = 0;
		if ((Check->tm_sec - tmp) == k) {
			for (int i = 0; i < 2; ++i)
				arrL[i].changeColor(arrL[i].getColor(), speed[0], speed[1]);
			tmp = Check->tm_sec;
		}
	}
}*/
void CGame::runningGame(int &level, char& current)
{
	for (int i = 0; i < size; i++)
	{
		if (cn.isImpact(arrC) || cn.isImpact(arrD) || cn.isImpact(arrB) || cn.isImpact(arrTr))
		{
			cn.setmState(0);
			return;
		}
	}
	if (cn.isFinishTurn(33))
	{
		score += 10;
		if (score % 30 == 0) level++;
		cn.erase();
		updatePosPeople(current, 1);
	}
}
CGame::~CGame()
{
	cn.setmState(1);
	arrL.clear();
	score = 0;
	stop = 0;
	size = 0;
}
void CGame::resetGame()
{
	this->~CGame();
}
void CGame::exitGame(HANDLE t, bool isSave)
{
	TerminateThread(t, 0);
	system("cls");
	if (isSave)
		saveGame();
	resetGame();
	system("cls");
	//exit(0);
}
void CGame::pauseGame(HANDLE t)
{
	SuspendThread(t);
}
void CGame::resumeGame(HANDLE t)
{
	ResumeThread(t);
}
void CGame::eraseString(string& str) {
	int i = 0;
	while (str.size() > 0 && str[i + 1] != NULL && str[i] != ',')
		++i;
	str.erase(str.begin() + 0, str.begin() + (i + 1));
}
void CGame::loadGame()
{
	resetGame();
	system("cls");
	cin.ignore();
	cout << "Format input [your location].txt" << endl;
	cout << "Enter your path: ";
	string s;  //D:\\CrossingRoad Repo\\Game1.txt
	getline(cin, s);
	if (s.size() == 0) getline(cin, s);
	cout << "Your path: " << s << endl;
	ifstream f;
	f.open(s + ".txt");
	cout << f.is_open();
	if (!f.is_open())
		cout << "Can not open file." << endl;
	else
	{
		CPoint pos;
		bool tmpState;
		int tmpColor, _speedTr, _speedB;
		f >> size >> score >> stop >> width >> _speedB >> _speedTr >> tmpColor >> pos.mX >> pos.mY >> tmpState;
		cn.setmState(tmpState);
		cn.setXY(pos.mX, pos.mY);

		arrTr.loadFile(f,size, _speedTr);
		arrC.loadFile(f,size, _speedTr);
		arrB.loadFile(f,size, _speedB);
		arrD.loadFile(f,size, _speedB);

		CTrafficLight objL(width, arrTr.getPosTraffic(), tmpColor);
		arrL.push_back(objL);
		CTrafficLight objL1(width, arrC.getPosTraffic(), tmpColor);
		arrL.push_back(objL1);

		stop = 0;
	}
	f.close();
}
void CGame::saveGame()
{
	TextColor(15);
	system("cls");
	cout << "Format input [your location].txt" << endl; 
	cout << "Enter your location: ";
	string s;                        //    D:\\CrossingRoad Repo
	getline(cin, s);
	if (s.size() == 0) getline(cin, s);
	cout << "\nYour path: " << s << ".txt" << endl;
	ofstream f;
	f.open(s + ".txt");
	cout << f.is_open();
	if (!f.is_open())
		cout << "Can not open file." << endl;
	else
	{
		f << size << " " << score << " " << stop << " " << width << " ";
		f << arrB.getSpeed() << " " << arrTr.getSpeed() << " "<< arrL[0].getColor() << " ";
		cn.outputFile(f);
		f << endl;
		arrTr.outputFile(f);
		f << endl;
		arrC.outputFile(f);
		f << endl;
		arrB.outputFile(f);
		f << endl;
		arrD.outputFile(f);
		f << endl;
		cout << "\nYour game is saved ! Press ESC to quit." << endl;
		system("pause");
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
