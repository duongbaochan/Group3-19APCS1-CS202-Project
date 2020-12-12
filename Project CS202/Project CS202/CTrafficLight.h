#pragma once
#include "Header.h"

class CTrafficLight
{
private:
	int mX;
	int mY;
public:
	CTrafficLight(int, int);
	void draw();
	void changeColor(int&, int);
	void wait(int);
};

