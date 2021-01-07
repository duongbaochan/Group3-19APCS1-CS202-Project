#include "CDinoInRange.h"

bool CDinoInRange::isDxAndDyInRange(CPoint x)
{
	if (x.mY == 1)
		return (x.mX >= 3 && x.mX <= 9);
	if (x.mY == 2)
		return (x.mX >= 3 && x.mX <= 9);
	if (x.mY == 3)
		return (x.mX >= 2 && x.mX <= 8);
	if (x.mY == 4)
		return (x.mX >= 4 && x.mX <= 8);
	return 0;
}