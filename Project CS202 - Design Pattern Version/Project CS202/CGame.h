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
	//CVehicle * getVehicle();//L?y danh s�ch c�c xe
	//CAnimal * getAnimal(); //L?y danh s�ch c�c th�
	void resetGame(); // Th?c hi?n thi?t l?p l?i to�n b? d? li?u nh? l�c ??u
	//void exitGame(HANDLE); 
	void startGame(int&, char&); // Th?c hi?n b?t ??u v�o tr� ch?i

	void eraseString(string& str);
	void loadGame(); 
	void saveGame(); 

	//void pauseGame(); 
	void runningGame(int&, char&);
	void updatePosPeople(char&, bool); //Th?c hi?n ?i?u khi?n di chuy?n c?a CPEOPLE
	
	
	int getScore();
	int getLevel();

	void exitGame(HANDLE t, bool isSave);
	void pauseGame(HANDLE t);
	void resumeGame(HANDLE t);
};

void Menu(CGame&);
void setConsoleSize(int width, int height);