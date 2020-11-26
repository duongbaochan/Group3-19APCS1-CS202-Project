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
