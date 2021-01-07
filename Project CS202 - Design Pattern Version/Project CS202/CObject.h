#pragma once
#include "CIsInRange.h"
#include "CDisplay.h"

class CObject
{
protected:
	CPoint pos;
	CIsInRange* objImpact;
	CDisplay* objDisp;
public:
	CObject(int, int);
	CObject(CPoint);
	~CObject();
	CObject();
	//CObject(const CObject &x);

	void setInRange(CIsInRange*);
	void setDisplay(CDisplay*);
	bool isInRange(CPoint) const;
	void display(bool isDraw, int textColor) const;
	void updatePos(int width, int speed);
};

