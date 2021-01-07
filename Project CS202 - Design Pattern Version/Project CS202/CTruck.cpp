#include "CTruck.h"

CTruck::CTruck() 
{
	CIsInRange* isImp = new CTruckInRange;
	setInRange(isImp);


	CDisplay* disp = new CTruckDisplay;
	setDisplay(disp);
}

// For Impact function
