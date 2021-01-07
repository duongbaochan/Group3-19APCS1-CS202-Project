#pragma once
#include "CIsInRange.h"
class CTruckInRange: public CIsInRange
{
public:
	bool isDxAndDyInRange(CPoint);
};

