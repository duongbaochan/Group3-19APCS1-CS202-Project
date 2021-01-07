#pragma once
#include "Header.h"
#include "CObject.h"

class CPeople {
protected:
	CPoint pos;
	bool mState = 1; //Tr?ng th�i s?ng ch?t
	int step;
public:
	//friend class CGame;

	CPeople();
	CPeople(int w);
	CPeople(int, int);

	void setXY(int, int);
	void setmState(int);

	void Up();
	void Left();
	void Right();
	void Down();
	bool isImpact(const CObject &x) const;
	bool isFinish();
	bool isDead();
	void Finish()
	{
		mState = 0;
	}
	bool isFinishTurn(int x)
	{
		if (pos.mY >= x)
			return 1;
		return 0;
	}
	void draw();
	void erase();
	void outputFile(ofstream& x)
	{
		x << pos.mX << " " << pos.mY << " " << mState;
	}
	void gotoXYPeople()
	{
		COORD coord;
		coord.X = pos.mX;
		coord.Y = pos.mY;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	}
};

