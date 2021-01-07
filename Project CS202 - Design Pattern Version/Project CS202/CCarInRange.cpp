#include "CCarInRange.h"

bool CCarInRange::isDxAndDyInRange(CPoint x)
{
	if (x.mY == 1)
		return (x.mX >= 2 && x.mX <= 9);
	if (x.mY == 2)
		return (x.mX >= 2 && x.mX <= 12);
	if (x.mY == 3)
		return (x.mX >= 5 && x.mX <= 10);
	return 0;
}