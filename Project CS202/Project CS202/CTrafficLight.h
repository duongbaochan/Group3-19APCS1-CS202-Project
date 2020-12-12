#pragma once
#include "Header.h"

class CTrafficLight
{
private:
	int mX;
	int mY;
	int color;
public:
	CTrafficLight(int, int);
	void draw();
	void changeColor(int, int);
	int getColor();
};

