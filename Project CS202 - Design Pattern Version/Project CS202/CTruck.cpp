#include "CTruck.h"

CTruck::CTruck(int x, int y) : CObject(x,y)
{
	CIsInRange* isImp = new CTruckInRange;
	setInRange(isImp);


	CDisplay* disp = new CTruckDisplay;
	setDisplay(disp);
}

// For Impact function
