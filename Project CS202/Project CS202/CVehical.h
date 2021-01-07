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

	virtual vector<vector<COORD>> boundaryMap(); //For Impact function
};
