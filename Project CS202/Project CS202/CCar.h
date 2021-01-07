#pragma once
#include "CVehical.h"

class CCar : public CVehicle
{
public:
	CCar(int, int);
	void draw(int, bool);

	vector<vector<COORD>> boundaryMap(); // For Impact
};
