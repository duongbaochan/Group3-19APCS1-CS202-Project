#pragma once
#include "CObject.h"
#include "CDinoDisplay.h"

class CDinausor: public CObject
{
public:
	CDinausor();
	vector<vector<CPoint>> boundary(int); // For Impact
};
