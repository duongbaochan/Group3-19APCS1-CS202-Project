#pragma once
#include "Header.h"

class CVehicle {
	int mX, mY;
public:
	virtual void Move(int, int);
	int getX();
	int getY();

	CVehicle(int, int);
};
