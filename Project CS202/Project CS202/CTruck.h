#pragma once
#include "CVehical.h"

class CTruck: public CVehicle
{
public:
	CTruck(int, int);
	void draw();

	// For Impact function
	bool isDxAndDyInRange(int, int);
};

