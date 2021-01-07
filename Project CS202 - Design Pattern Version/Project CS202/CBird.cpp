#include "CBird.h"

CBird::CBird(int x, int y) : CObject(x, y)
{
	CIsInRange* isImp = new CBirdInRange;
	setInRange(isImp);


	CDisplay* disp = new CBirdDisplay;
	setDisplay(disp);
}