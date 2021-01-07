#include "CObject.h"

CObject::CObject(int x, int y)
{
	pos.mX = x;
	pos.mY = y;
	objImpact = NULL;
	objDisp = NULL;
}
CObject::CObject(CPoint x)
{
	pos = x;
	objImpact = NULL;
	objDisp = NULL;
}
CObject::~CObject()
{
	delete objDisp;
	delete objImpact;
}
CObject::CObject()
{
	pos.mX = 0;
	pos.mY = 0;
	objImpact = NULL;
	objDisp = NULL;
}
void CObject::setInRange(CIsInRange* x)
{
	objImpact = x;
}
void CObject::setDisplay(CDisplay* x){
	objDisp = x;
}
bool CObject::isInRange(CPoint x) const{
	x.mX -= pos.mX;
	x.mY -= pos.mY;
	if (this->objImpact)
	{
		PlaySound(TEXT("Sounds/woosh_2.wav"), NULL, SND_SYNC);
		return this->objImpact->isDxAndDyInRange(x);
	}
	return 0;
}
void CObject::display(bool isDraw, int textColor) const{
	if (this->objDisp)
		this->objDisp->display(pos, isDraw, textColor);
}
void CObject::updatePos(int width, int speed)
{
	pos.mX = pos.mX + speed;
	if (pos.mX >= 0)
		pos.mX %= width;
}