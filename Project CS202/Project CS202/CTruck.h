#pragma once
#include "CVehical.h"

class CTruck : public CVehicle
{
public:
	CTruck(int, int);
	void draw(int, bool);

	vector<vector<COORD>> boundaryMap(); // For Impact
};

