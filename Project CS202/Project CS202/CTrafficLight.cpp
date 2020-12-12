#include "CTrafficLight.h"

CTrafficLight::CTrafficLight(int x, int y) : mX(x), mY(y) {
}

void CTrafficLight::draw() {
	if (mX > 0 && mX < 85) {
		GotoXY(mX, mY);
		TextColor(6);
		cout << " _____";
		GotoXY(mX, mY + 1);
		cout << "|";
		//GotoXY(mX + 2, mY + 1);
		//cout << "**";
		GotoXY(mX + 5, mY + 1);
		cout << "|";
		GotoXY(mX, mY + 2);
		cout << "|_";
		//GotoXY(mX + 2, mY + 2);
		//cout << "**";
		GotoXY(mX + 4, mY + 2);
		cout << "_|";
		GotoXY(mX, mY + 3);
		cout << "_| |_";
		TextColor(15);
	}
}
void CTrafficLight::changeColor(int& color, int k) {
	switch (color) {
	case 10: //green -> red
		//wait(k);
		color = 12;
		break;
	case 12: //red -> yellow
		//wait(k);
		color = 14;
		break;
	case 14: //yellow -> green
		//wait(k);
		color = 10;
		break;
	}
	TextColor(color);
	GotoXY(mX + 2, mY + 1);
	cout << "**";
	GotoXY(mX + 2, mY + 2);
	cout << "**";
	TextColor(15);
}

void CTrafficLight::wait(int k) {
	/*
	time_t t = time(0);
	tm* Check = localtime(&t);
	
	if (difftime(mktime(Check), t) > 0 && difftime(mktime(Check), t) <= 1800)
	*/
	clock_t t = clock();
	while (1) {
		if ((clock() - t) == k) {
			break;
		}
	}
}
