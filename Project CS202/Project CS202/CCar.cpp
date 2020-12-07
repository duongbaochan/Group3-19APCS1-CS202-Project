#include "CCar.h"

CCar::CCar(int x, int y) : CVehicle(x, y)
{

}
void CCar::draw()
{
	GotoXY(mX, mY);
	if (mX > 0 && mX < 85) {
		TextColor(5);
		cout << "   _____";
		GotoXY(mX, mY + 1);
		cout << " _/     \\__";
		GotoXY(mX-1, mY + 2);
		cout << " |__________|";
		GotoXY(mX, mY + 3);
		cout << "  ()----()";
		TextColor(15);
		//cout << "C" << endl;
	}
}

// For Impact function
bool CCar::isDxAndDyInRange(int Dx, int Dy)
{
	if (Dy == 1)
		return (Dx >= 2 && Dx <= 9);
	if (Dy == 2)
		return (Dx >= 2 && Dx <= 12);
	if (Dy == 3)
		return (Dx >= 5 && Dx <= 10);
	return 0;
}