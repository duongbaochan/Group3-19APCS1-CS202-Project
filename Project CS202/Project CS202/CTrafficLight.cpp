#include "CTrafficLight.h"

CTrafficLight::CTrafficLight(int x, int y) : mX(x), mY(y) {
	color = 10;
}

void CTrafficLight::draw() {
	if (mX > 0) {
		GotoXY(mX, mY);
		TextColor(15);
		cout << " _____";
		GotoXY(mX, mY + 1);
		cout << "|";
		GotoXY(mX + 2, mY + 1);
		TextColor(color);
		cout << "**";
		TextColor(15);
		GotoXY(mX + 5, mY + 1);
		cout << "|";
		GotoXY(mX, mY + 2);
		cout << "|_";
		GotoXY(mX + 2, mY + 2);
		TextColor(color);
		cout << "**";
		TextColor(15);
		GotoXY(mX + 4, mY + 2);
		cout << "_|";
		GotoXY(mX, mY + 3);
		cout << "_| |_";
		TextColor(15);
	}
}
void CTrafficLight::changeColor(int tmp_color, int &k) {
	switch (tmp_color) {
	case 10: //green -> red
		color = 12;
		k = 0;
		break;
	case 12: //red -> yellow
		color = 6;
		k = 1;
		break;
	case 6: //yellow -> green
		color = 10;
		k = 2;
		break;
	}
}

int CTrafficLight::getColor() {
	return color;
}