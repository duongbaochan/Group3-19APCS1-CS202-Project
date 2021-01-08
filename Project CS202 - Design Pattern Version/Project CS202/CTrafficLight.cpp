#include "CTrafficLight.h"

CTrafficLight::CTrafficLight(int x, int y) : idx(x, y)
{
	color = 10;
}

CTrafficLight::CTrafficLight(int x, int y, int z) : idx(x, y)
{
	color = z;
}

void CTrafficLight::draw() 
{
	if (idx.mX > 0) {
		GotoXY(idx.mX, idx.mY);
		TextColor(15);
		cout << "______";
		GotoXY(idx.mX, idx.mY + 1);
		cout << "|";
		GotoXY(idx.mX + 2, idx.mY + 1);
		TextColor(color);
		cout << "**";
		TextColor(15);
		GotoXY(idx.mX + 5, idx.mY + 1);
		cout << "|";
		GotoXY(idx.mX, idx.mY + 2);
		cout << "|_";
		GotoXY(idx.mX + 2, idx.mY + 2);
		TextColor(color);
		cout << "**";
		TextColor(15);
		GotoXY(idx.mX + 4, idx.mY + 2);
		cout << "_|";
		GotoXY(idx.mX, idx.mY + 3);
		cout << " _||_";
		TextColor(15);
	}
}
void CTrafficLight::changeColor(int tmp_color, int &k, int pre_speed)
{
	switch (tmp_color) 
	{
	case 10: //green -> red
		color = 12;
		k = 0;
		break;
	case 12: //red -> yellow
		color = 6;
		k = pre_speed/2;
		break;
	case 6: //yellow -> green
		color = 10;
		k = pre_speed;
		break;
	}
}

int CTrafficLight::getColor()
{
	return color;
}