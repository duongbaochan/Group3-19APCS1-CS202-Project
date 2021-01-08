#pragma once
#include "CObject.h"
#include "CCarDisplay.h"

class CCar : public CObject
{
public:
	CCar();
	vector<vector<CPoint>> boundary(int); // For Impact
};
