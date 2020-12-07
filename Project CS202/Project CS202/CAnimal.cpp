#include "CAnimal.h"

int CAnimal::getX()
{
	return mX;
}
int CAnimal::getY()
{
	return mY;
}

CAnimal::CAnimal(int x, int y)
{
	mX = x;
	mY = y;
}
void CAnimal::updatePosAnimal(int width)
{
	mX = mX + 1;
	if (mX >= 0)
		mX %= width;
}

bool CAnimal::isDxAndDyInRange(int, int)
{
	return 0;
}