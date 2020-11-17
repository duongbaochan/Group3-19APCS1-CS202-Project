#ifndef FUNCTION_H_
#define FUNCTION_H_
#include <iostream>
#include <string>
using namespace std;

class CPeople {
	int mX, mY;
	bool mState; //Tr?ng thái s?ng ch?t
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
	 CGame(); //Chu?n b? d? li?u cho t?t c? các ??i t??ng
	 void drawGame(); //Th?c hi?n v? trò ch?i ra màn hình sau khi có d? li?u
	 ~CGame(); // H?y tài nguyên ?ã c?p phát
	 CPeople getPeople();//L?y thông tin ng??i
	 CVehicle * getVehicle();//L?y danh sách các xe
	 CAnimal * getAnimal(); //L?y danh sách các thú
	 void resetGame(); // Th?c hi?n thi?t l?p l?i toàn b? d? li?u nh? lúc ??u
	 void exitGame(HANDLE); // Th?c hi?n thoát Thread
	 void startGame(); // Th?c hi?n b?t ??u vào trò ch?i
	 void loadGame(istream); // Th?c hi?n t?i l?i trò ch?i ?ã l?u
	 void saveGame(istream); // Th?c hi?n l?u l?i d? li?u trò ch?i
	 void pauseGame(HANDLE); // T?m d?ng Thread
	 void resumeGame(HANDLE); //Quay lai Thread
	 void updatePosPeople(char); //Th?c hi?n ?i?u khi?n di chuy?n c?a CPEOPLE
	 void updatePosVehicle(); //Th?c hi?n cho CTRUCK & CCAR di chuy?n
	 void updatePosAnimal();//Th?c hi?n cho CDINAUSOR & CBIRD di chuy?n
}








#endif;
