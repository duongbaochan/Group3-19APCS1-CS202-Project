#pragma once
#include "Header.h"

class CVehicle {
protected:
	int mX, mY;
public:
	//virtual void Move(int, int);
	int getX();
	int getY();
	void updatePosVehicle(int, int);
	CVehicle(int, int);

	// For Impact function
	virtual bool isDxAndDyInRange(int, int);
};
