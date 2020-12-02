#include "CTruck.h"

CTruck::CTruck(int x, int y) : CVehicle(x, y)
{

}
void CTruck::draw()
{
	if (mX > 0  && mX < 85) {
		GotoXY(mX-1, mY);
		TextColor(8);
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