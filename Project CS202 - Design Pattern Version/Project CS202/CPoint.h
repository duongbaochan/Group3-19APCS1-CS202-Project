#pragma once
#include "Header.h"
class CPoint
{
public:
	int mX, mY;
	CPoint(int x, int y)
	{
		mX = x;
		mY = y;
	}
	CPoint(const CPoint &x)
	{
		mX = x.mX;
		mY = x.mY;
	}
	CPoint()
	{
		mX = mY = 0;
	}
};

