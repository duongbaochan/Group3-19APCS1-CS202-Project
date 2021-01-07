#include "CVehical.h"

int CVehicle::getX()
{
	return mX;
}
int CVehicle::getY()
{
	return mY;
}

CVehicle::CVehicle(int x, int y)
{
	mX = x;
	mY = y;
}
void CVehicle::updatePosVehicle(int width, int speed)
{
	mX = mX + speed;
	if (mX >= 0)
		mX %= width;
}

vector<vector<COORD>> CVehicle::boundaryMap() // For Impact function
{
	COORD p;
	p.X = -1;
	p.Y = -1;
	return { {p} };
}