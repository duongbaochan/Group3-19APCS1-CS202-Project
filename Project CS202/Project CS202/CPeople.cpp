#include "CPeople.h"

CPeople::CPeople()
{
	mX = mY = 0;
}
CPeople::CPeople(int w)
{
	mX = 50;
	mY = 0;
}

CPeople::CPeople(int mX, int mY)
{
	this->mX = mX;
	this->mY = mY;
}

void CPeople::Up()
{
	mX -= step;
}
void CPeople::Left()
{
	mY -= step;
}
void CPeople::Right()
{
	mY += step;
}
void CPeople::Down()
{
	mX += step;
}

bool CPeople::isFinish()
{
	return mState;
}

bool CPeople::isDead()
{
	return mState;
}
bool CPeople::isImpact(CVehicle* x) 
{
	int tmp_x = 0;
	for (int i = 0; i < 4; i++)
	{
		tmp_x = abs(mX - x->getX());
		if (tmp_x <= 11 && mY == x->getY() + i)
			return 1;
	}
	return 0;
}
bool CPeople::isImpact(CAnimal* x)
{
	int tmp_x = 0; 
	for (int i = 0; i < 4; i++)
	{
		tmp_x = abs(mX - x->getX());
		if (tmp_x <= 10 && mY == x->getY() + i)
			return 1;
	}
	return 0;
}
void CPeople::draw()
{

}
