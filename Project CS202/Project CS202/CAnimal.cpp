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
void CAnimal::updatePosAnimal(int width, int speed)
{
	mX = mX + speed;
	if (mX >= 0)
		mX %= width;
}

vector<vector<COORD>> CAnimal::boundaryMap() // For Impact function
{
	COORD p;
	p.X = -1;
	p.Y = -1;
	return { {p} };
}