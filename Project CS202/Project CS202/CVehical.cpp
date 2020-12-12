#include "CVehical.h"

int CVehicle::getX()
{
	return mX;
}
int CVehicle::getY()
{
	return mY;
}
int CVehicle::getSpeed() {
	return speed;
}
void CVehicle::setSpeed(int a) {
	speed = a;
}

CVehicle::CVehicle(int x, int y)
{
	mX = x;
	mY = y;
}
void CVehicle::updatePosVehicle(int width)
{
	mX = mX + 1;
	if (mX >= 0)
		mX %= width;
}

// For Impact function
bool CVehicle::isDxAndDyInRange(int Dx, int Dy)
{
	return 0;
}