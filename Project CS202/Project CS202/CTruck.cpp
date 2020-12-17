#include "CTruck.h"

CTruck::CTruck(int x, int y) : CVehicle(x, y)
{

}
void CTruck::draw(int textColor, bool isDraw)
{
	if (!isDraw) return;
	if (mX > 0  && mX < 85) {
		GotoXY(mX-1, mY);
		TextColor(textColor);
		//TextColor(8);
		cout << " ___________";
		GotoXY(mX-1, mY + 1);
		cout << " |         \\\\_";
		GotoXY(mX-1, mY + 2);
		cout << " |____________|";
		GotoXY(mX, mY + 3);
		cout << "  ()-----()";
		TextColor(15);
	}
}

// For Impact function
bool CTruck::isDxAndDyInRange(int Dx, int Dy)
{
	if (Dy == 1)
		return (Dx >= 2 && Dx <= 12);
	if (Dy == 2)
		return (Dx >= 4 && Dx <= 14);
	if (Dy == 3)
		return (Dx >= 4 && Dx <= 11);
	return 0;
}