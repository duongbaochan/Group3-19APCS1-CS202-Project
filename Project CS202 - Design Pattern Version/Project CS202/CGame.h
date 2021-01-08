#pragma once
#include "CTruck.h"
#include "CCar.h"
#include "CDinausor.h"
#include "CBird.h"
#include "CPeople.h"
#include "CTrafficLight.h"



class CGame
{

	CTruck arrTr;
	CCar arrC;
	CDinausor arrD;
	CBird arrB;
	
	vector <CTrafficLight> arrL;
	CPeople cn;
	int size;
	int score;
	bool stop = 0;
	int width;
public:
	
	CGame();
	void setGame(int, int, int, int, int, int);
	//void setGame();
	void drawGame(string, int); 
	~CGame(); 
	CPeople getPeople();
	void resetGame(); 
	void startGame(int&, char&); 

	void eraseString(string& str);
	void loadGame(); 
	void saveGame(); 

	void setGame(int); 
	void runningGame(int&, char&);
	void updatePosPeople(char&, bool);
	
	
	int getScore();
	int getLevel();

	void exitGame(HANDLE t, bool isSave);
	void pauseGame(HANDLE t);
	void resumeGame(HANDLE t);
};

void Menu(CGame&);
void setConsoleSize(int width, int height);