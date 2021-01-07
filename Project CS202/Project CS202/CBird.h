#pragma once
#include "CAnimal.h"

class CBird : public CAnimal
{
public:
	CBird(int, int);
	void draw(int, bool);

	vector<vector<COORD>> boundaryMap(); // For Impact
};

