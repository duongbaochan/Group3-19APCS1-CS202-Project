#include "CDinausor.h"

CDinausor::CDinausor() 
{
	CIsInRange* isImp = new CDinoInRange;
	setInRange(isImp);


	CDisplay* disp = new CDinoDisplay;
	setDisplay(disp);
}