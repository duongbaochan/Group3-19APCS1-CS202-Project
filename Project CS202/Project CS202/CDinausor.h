#pragma once
#include "CAnimal.h"

class CDinausor: public CAnimal
{
public:
	CDinausor(int, int);
	void draw(int, bool);

	vector<vector<COORD>> boundaryMap(); // For Impact function
};
