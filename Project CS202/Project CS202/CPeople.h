#pragma once
#include "Header.h"
#include "CVehical.h"
#include "CAnimal.h"

class CPeople {
protected:
	int mX, mY;
	bool mState = 1; //Tr?ng thái s?ng ch?t
	int step;
public:
	CPeople();
	CPeople(int w);
	CPeople(int, int);

	void setXY(int, int);
	void Up();
	void Left();
	void Right();
	void Down();
	bool isImpact(CVehicle*);
	bool isImpact(CAnimal*);
	bool isFinish();
	bool isDead();
	void draw();
};

