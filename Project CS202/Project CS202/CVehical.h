#pragma once
#include "Header.h"

class CVehicle {
protected:
	int mX, mY;
	int speed;
public:
	//virtual void Move(int, int);
	int getX();
	int getY();
	int getSpeed();
	void setSpeed(int);
	void updatePosVehicle(int, int);
	CVehicle(int, int);

	// For Impact function
	virtual bool isDxAndDyInRange(int, int);
};
