#include "CCar.h"

CCar::CCar(/*int x, int y*/)
{
	CIsInRange* isImp = new CCarInRange;
	setInRange(isImp);


	CDisplay* disp = new CCarDisplay;
	setDisplay(disp);
}


// For Impact function
