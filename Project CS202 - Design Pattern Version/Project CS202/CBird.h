#pragma once
#include "CObject.h"
#include "CBirdDisplay.h"

class CBird : public CObject
{
public:
	//CBird(int, int);
	CBird();
	vector<vector<CPoint>> boundary(int);
};

