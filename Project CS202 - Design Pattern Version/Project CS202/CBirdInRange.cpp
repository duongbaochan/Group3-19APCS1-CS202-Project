#include "CBirdInRange.h"

bool CBirdInRange::isDxAndDyInRange(CPoint x)
{
	if (x.mX == 0)
		return (x.mX >= 3 && x.mX <= 4);
	if (x.mY == 1)
		return (x.mX >= 2 && x.mX <= 7);
	if (x.mY == 2)
		return (x.mX >= 2 && x.mX <= 10);
	if (x.mY == 3)
		return (x.mX >= 3 && x.mX <= 4);
	return 0;
}
