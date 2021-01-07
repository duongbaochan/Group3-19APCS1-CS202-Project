#include "CBird.h"

CBird::CBird()
{
	CIsInRange* isImp = new CBirdInRange;
	setInRange(isImp);


	CDisplay* disp = new CBirdDisplay;
	setDisplay(disp);
}