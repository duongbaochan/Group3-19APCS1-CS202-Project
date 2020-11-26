#ifndef FUNCTION_H_
#define FUNCTION_H_
#include <iostream>
#include <string>
using namespace std;

class CPeople {
	int mX, mY;
	bool mState; //Tr?ng th�i s?ng ch?t
public:
	CPeople();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(const CVehicle*&);
	bool isImpact(const CAnimal*&);
	bool isFinish();
	bool isDead();
}

class CVehicle {
	int mX, mY;
public:
	virtual void Move(int, int);
	//...
};

class CAnimal {
	int mX, mY;
public:
	virtual void Move(int, int);
	virtual void Tell();
};

class CGame {
	 CTruck * axt;
	 CCar * axh;
	 CDinausor* akl;
	 CBird * ac;
	 CPeople cn;
public:
	 CGame(); //Chu?n b? d? li?u cho t?t c? c�c ??i t??ng
	 void drawGame(); //Th?c hi?n v? tr� ch?i ra m�n h�nh sau khi c� d? li?u
	 ~CGame(); // H?y t�i nguy�n ?� c?p ph�t
	 CPeople getPeople();//L?y th�ng tin ng??i
	 CVehicle * getVehicle();//L?y danh s�ch c�c xe
	 CAnimal * getAnimal(); //L?y danh s�ch c�c th�
	 void resetGame(); // Th?c hi?n thi?t l?p l?i to�n b? d? li?u nh? l�c ??u
	 void exitGame(HANDLE); // Th?c hi?n tho�t Thread
	 void startGame(); // Th?c hi?n b?t ??u v�o tr� ch?i
	 void loadGame(istream); // Th?c hi?n t?i l?i tr� ch?i ?� l?u
	 void saveGame(istream); // Th?c hi?n l?u l?i d? li?u tr� ch?i
	 void pauseGame(HANDLE); // T?m d?ng Thread
	 void resumeGame(HANDLE); //Quay lai Thread
	 void updatePosPeople(char); //Th?c hi?n ?i?u khi?n di chuy?n c?a CPEOPLE
	 void updatePosVehicle(); //Th?c hi?n cho CTRUCK & CCAR di chuy?n
	 void updatePosAnimal();//Th?c hi?n cho CDINAUSOR & CBIRD di chuy?n
}








#endif;

