#pragma once
class CTrafficLight
{
private:
	int mX;
	int mY;
public:
	CTrafficLight(int, int);
	void changeColor(int second);
};

