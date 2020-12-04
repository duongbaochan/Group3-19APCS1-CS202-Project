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
	int Dx = -1, Dy = -1;
	Dx = mX - x->getX();
	Dy = mY - x->getY();

	if (x->isDxAndDyInRange(Dx, Dy))
		return 1;

	return 0;
}
bool CPeople::isImpact(CAnimal* x)
{
	int Dx = -1, Dy = -1;
	Dx = mX - x->getX();
	Dy = mY - x->getY();

	if (x->isDxAndDyInRange(Dx, Dy))
		return 1;

	return 0;
}
void CPeople::draw()
{

}
