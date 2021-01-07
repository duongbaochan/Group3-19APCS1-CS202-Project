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

// For Impact function
bool CVehicle::isDxAndDyInRange(int Dx, int Dy)
{
	return 0;
}