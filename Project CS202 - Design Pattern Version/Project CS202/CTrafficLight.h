#pragma once
#include "Header.h"
#include "CPoint.h"

class CTrafficLight
{
private:
	CPoint idx;
	int color;
public:
	CTrafficLight(int, int);
	CTrafficLight(int, int, int);
	void draw();
	void changeColor(int, int&, int);
	int getColor();
};

