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
