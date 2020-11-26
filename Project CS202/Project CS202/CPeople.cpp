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
	if (mX == x->getX() && mY == x->getY())
		return 1;
	return 0;
}
bool CPeople::isImpact(CAnimal* x)
{
	if (mX == x->getX() && mY == x->getY())
		return 1;
	return 0;
}
void CPeople::draw()
{

}
