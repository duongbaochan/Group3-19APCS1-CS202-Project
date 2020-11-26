#pragma once

class CAnimal {
	int mX, mY;
public:
	virtual void Move(int, int);
	virtual void Tell();
	int getX();
	int getY();

	CAnimal(int, int);

};
