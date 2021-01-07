#include "CGame.h"


void Menu(CGame& x)
{
	cout << "----------------MENU--------------" << endl;
	cout << "        WELCOME TO THE GAME       " << endl;
	cout << "1. New Game." << endl;
	cout << "2. Load Game." << endl;
	cout << "3. Settings." << endl;
	cout << "0. Exit." << endl;
	cout << "Enter our option: ";
	int n; cin >> n;

	while (true) {
		try {
			if (cin.fail())
				throw n;
		}

		catch (...) {
			cout << "Exception caught from input (Invalid input format). Exiting...\n";
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
				x.setGame(level, 1, 100, x.getScore(), x.getXPeople(), x.getYPeople());
				return;
			}
			else if (n == 0) return;
			else throw n;
		}
		catch (int n) {
			cout << "Exception caught from input (Input option is not available). Exiting...\n";
		}
	}


	//while (n)
	//{
	//	if (n == 1)
	//	{
	//		CGame x(5, 1, 100, 0, 50, 0);
	//		x.startGame(5);
	//		break;
	//	}
	//	else if (n == 2)
	//	{
	//		CGame x;
	//		x.loadGame();
	//		break;
	//	}
	//	else if (n == 0) return;
	//	else
	//	{
	//		cout << "Please choose again...";
	//		cin >> n;
	//	}
	//}
	//}
}

int CGame::getXPeople()
{
	return cn.getX();
}

int CGame::getYPeople()
{
	return cn.getY();
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
	//x(1, 1, 100, 0, 50, 0)
	stop = 0;
	//srand(time(NULL));
	score = _score;
	size = _size;
	width = _width;
	FixConsoleWindow();
	unsigned short k = rand() % 4;
	for (int i = 1; i <= size; i++)
	{
		CTruck* objT = new CTruck(0 - i * _width / size + rand()%7, k * 8 + 2);
		CCar* objC = new CCar(0 - i * _width / size + 40 + rand() % 7, (k + 1) % 4 * 8 + 2);
		CBird* objB = new CBird(0 - i * _width / size -10 + rand() % 15, (k + 2) % 4 * 8 + 2);
		CDinausor* objD = new CDinausor(0 - i * _width / size +  15 + rand() % 15, (k + 3) % 4 * 8 + 2);
		
		arrTr.push_back(objT);
		arrC.push_back(objC);
		arrB.push_back(objB);
		arrD.push_back(objD);
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

/*	for (int i = 0; i < size; i++)
	{
		arrTr[i]->draw(0,speed[0]);
		arrC[i]->draw(0, speed[0]);
		arrB[i]->draw(0,1);
		arrD[i]->draw(0,1);
	}*/
	//TextColor(15);
	//updatePosVehicle();
	//updatePosAnimal();
	//if (arrL[1].getColor() == 12)
		//Sleep(5);
	for (int i = 0; i < size; i++)
	{
		arrTr[i]->draw(0, speed[0]);
		arrTr[i]->updatePosVehicle(width, speed[0]);
		arrTr[i]->draw(3, speed[0]);

		
		arrC[i]->draw(0, speed[0]);
		arrC[i]->updatePosVehicle(width, speed[0]);
		arrC[i]->draw(5, speed[0]);

		arrB[i]->draw(0, 1);
		arrB[i]->updatePosAnimal(width, speed[1]);
		arrB[i]->draw(7, 1);

		arrD[i]->draw(0, 1);
		arrD[i]->updatePosAnimal(width, speed[1]);
		arrD[i]->draw(9, 1);

	}
	for (int i = 0; i < 2; ++i)
		arrL[i].draw();
}
void CGame::updatePosPeople(char& current, bool flag)
{
	//GotoXY(cn.mX, cn.mY);
	//cout << "N:";
    //cn.draw();
	GotoXY(100, 0);
	cout << "Score: " << score;
	GotoXY(100, 1);
	cout << "Level: " << (score / 40) + 1;


	if (cn.mY == 7 || cn.mY == 14 || cn.mY == 22 || cn.mY == 29)
	{
		score += 10;
		++cn.mY;
	}

	if (flag == 1)
		cn.setXY(50, 0);

	GotoXY(cn.mX, cn.mY);
	//cout << "N:";
    cn.draw();
	//if (flag == 1)
	//{
	//	cn.setXY(100 / 2, 0);
	//}

	if (current == 'A' || current == 'D' || current == 'W' || current == 'S'|| current == 'L') {
		cn.erase();
		switch (current) {
		case 'A':
			cn.mX--;
			break;
		case 'D':
			cn.mX++;
			break;
		case 'W':
			cn.mY--;
			break;
		case 'S':
			cn.mY++;
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
void CGame::startGame(int &level, char& current)
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
		//if (cn.mState == 0)
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
		if (tmp > 56)
			tmp = 0;
		if ((Check->tm_sec - tmp) == k) {
			for (int i = 0; i < 2; ++i)
				arrL[i].changeColor(arrL[i].getColor(), speed[0], speed[1]);
			tmp = Check->tm_sec;
		}
	//	updatePosVehicle();
	//	updatePosAnimal();
	}
}
void CGame::runningGame(int level, char& current)
{
	for (int i = 0; i < size; i++)
	{
		if (cn.isImpact(arrC[i]) || cn.isImpact(arrD[i]) || cn.isImpact(arrB[i]) || cn.isImpact(arrTr[i]))
		{
			cn.mState = 0;
			return;
		}
	}
	//if (cn.mY == level + 18)
	//{
	//	cn.Finish();
	//	return;
	//}
	if (cn.isFinishTurn(level + 24))
		updatePosPeople(current, 1);
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
	cin.ignore();
	cout << "Enter your path: ";
	string s;  //D:\\CrossingRoad Repo\\Game1.txt
	getline(cin, s);
	ifstream f;
	f.open(s);
	if (!f.is_open())
		cout << "Can not open file." << endl;
	else
		f >> size >> score >> stop >> width >> cn.mX >> cn.mY >> cn.mState;
	f.close();
	//this->startGame(size);
}
void CGame::saveGame()
{
	cin.ignore();
	cout << "Enter your location: ";
	string s;                        //    D:\\CrossingRoad Repo
	getline(cin, s);
	GotoXY(cn.mX + 2, cn.mY + 1);
	cout << "Enter the name of this current save: ";
	string filename;
	getline(cin, filename);
	ofstream f;
	f.open(s + "\\" + filename + ".txt");
	if (!f.is_open())
		cout << "Can not open file." << endl;
	else
		f << size << " " << score << " " << stop << " " << width << " " << cn.mX << " " << cn.mY << " " << cn.mState;
	f.close();
	GotoXY(cn.mX + 2, cn.mY + 2);
	cout << "Your game is saved ! Press ESC to quit.";
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
