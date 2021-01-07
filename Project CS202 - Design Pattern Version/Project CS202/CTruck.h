#pragma once
#include "CVehical.h"

class CTruck : public CVehicle
{
public:
	CTruck(int, int);
	void draw(int, bool);

	// For Impact function
	bool isDxAndDyInRange(int, int);
};

