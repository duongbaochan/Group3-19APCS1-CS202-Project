#include "CTruckInRange.h"

bool CTruckInRange::isDxAndDyInRange(CPoint x)
{
	if (x.mY == 1)
		return (x.mX >= 2 && x.mX <= 12);
	if (x.mY == 2)
		return (x.mX >= 4 && x.mX <= 14);
	if (x.mY == 3)
		return (x.mX >= 4 && x.mX <= 11);
	return 0;
}