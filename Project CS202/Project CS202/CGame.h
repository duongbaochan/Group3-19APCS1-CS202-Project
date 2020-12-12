#pragma once
#include "CTruck.h"
#include "CCar.h"
#include "CDinausor.h"
#include "CBird.h"
#include "CPeople.h"
#include "CTrafficLight.h"

class CGame:public CPeople 
{
	vector <CTruck*> arrTr;
	vector <CCar*> arrC;
	vector <CDinausor*> arrD;
	vector <CBird*> arrB;
	vector <CTrafficLight> arrL;
	int size;
	int score = 0;
	bool stop;
	int width;
//	CPeople cn;
public:
	CGame();
	CGame(int, int, int); //Chu?n b? d? li?u cho t?t c? các ??i t??ng
	void drawGame(); //Th?c hi?n v? trò ch?i ra màn hình sau khi có d? li?u
	~CGame(); // H?y tài nguyên ?ã c?p phát
	//CPeople getPeople();//L?y thông tin ng??i
	//CVehicle * getVehicle();//L?y danh sách các xe
	//CAnimal * getAnimal(); //L?y danh sách các thú
	void resetGame(); // Th?c hi?n thi?t l?p l?i toàn b? d? li?u nh? lúc ??u
	void exitGame(HANDLE); // Th?c hi?n thoát Thread
	void startGame(int); // Th?c hi?n b?t ??u vào trò ch?i
	void loadGame(); // Th?c hi?n t?i l?i trò ch?i ?ã l?u
	void saveGame(); // Th?c hi?n l?u l?i d? li?u trò ch?i
	void pauseGame(HANDLE); // T?m d?ng Thread
	void resumeGame(HANDLE); //Quay lai Thread
	void runningGame(int);
	void updatePosPeople(bool); //Th?c hi?n ?i?u khi?n di chuy?n c?a CPEOPLE
	void updatePosVehicle(int); //Th?c hi?n cho CTRUCK & CCAR di chuy?n
	void updatePosAnimal();//Th?c hi?n cho CDINAUSOR & CBIRD di chuy?n
};

void Menu();

