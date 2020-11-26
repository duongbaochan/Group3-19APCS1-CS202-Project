#pragma once
#include "Header.h"
#include "CVehical.h"
#include "CAnimal.h"

class CPeople {
	int mX, mY;
	bool mState; //Tr?ng th�i s?ng ch?t
	int step;
public:
	CPeople();
	CPeople(int w);

	void Up();
	void Left();
	void Right();
	void Down();
	bool isImpact(CVehicle*);
	bool isImpact(CAnimal*);
	bool isFinish();
	bool isDead();
}

