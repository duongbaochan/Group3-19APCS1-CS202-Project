#pragma once
#include "CAnimal.h"

class CBird:public CAnimal
{
public:
	CBird(int, int);
	void draw();

	// For Impact function
	bool isDxAndDyInRange(int, int);
};

