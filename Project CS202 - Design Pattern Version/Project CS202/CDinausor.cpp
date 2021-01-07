#include "CDinausor.h"

CDinausor::CDinausor(int x, int y) : CObject(x, y)
{
	CIsInRange* isImp = new CDinoInRange;
	setInRange(isImp);


	CDisplay* disp = new CDinoDisplay;
	setDisplay(disp);
}