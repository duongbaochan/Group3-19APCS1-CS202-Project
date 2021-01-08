#pragma once
#include "CObject.h"
#include "CTruckDisplay.h"

class CTruck : public CObject
{
public:
	CTruck();
	vector<vector<CPoint>> boundary(int); // For Impact
};

