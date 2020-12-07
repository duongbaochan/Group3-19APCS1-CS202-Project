#pragma once
#include "CTruck.h"
#include "CCar.h"
#include "CDinausor.h"
#include "CBird.h"
#include "CPeople.h"

class CGame:public CPeople 
{
	vector <CTruck*> arrTr;
	vector <CCar*> arrC;
	vector <CDinausor*> arrD;
	vector <CBird*> arrB;
	int size;
	int score = 0;
	bool stop;
	int width;
//	CPeople cn;
public:
	CGame();
	CGame(int, int, int); //Chu?n b? d? li?u cho t?t c? c�c ??i t??ng
	void drawGame(); //Th?c hi?n v? tr� ch?i ra m�n h�nh sau khi c� d? li?u
	~CGame(); // H?y t�i nguy�n ?� c?p ph�t
	//CPeople getPeople();//L?y th�ng tin ng??i
	//CVehicle * getVehicle();//L?y danh s�ch c�c xe
	//CAnimal * getAnimal(); //L?y danh s�ch c�c th�
	void resetGame(); // Th?c hi?n thi?t l?p l?i to�n b? d? li?u nh? l�c ??u
	void exitGame(HANDLE); // Th?c hi?n tho�t Thread
	void startGame(int); // Th?c hi?n b?t ??u v�o tr� ch?i
	void loadGame(); // Th?c hi?n t?i l?i tr� ch?i ?� l?u
	void saveGame(); // Th?c hi?n l?u l?i d? li?u tr� ch?i
	void pauseGame(HANDLE); // T?m d?ng Thread
	void resumeGame(HANDLE); //Quay lai Thread
	void runningGame(int);
	void updatePosPeople(bool); //Th?c hi?n ?i?u khi?n di chuy?n c?a CPEOPLE
	void updatePosVehicle(); //Th?c hi?n cho CTRUCK & CCAR di chuy?n
	void updatePosAnimal();//Th?c hi?n cho CDINAUSOR & CBIRD di chuy?n
};

void Menu();

