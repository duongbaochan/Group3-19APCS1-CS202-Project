#include "CTruck.h"

CTruck::CTruck(int x, int y) : CVehicle(x, y)
{

}
void CTruck::draw()
{
	GotoXY(mX, mY);
	if (mX > 0) {
		TextColor(8);
		cout << "___________";
		GotoXY(mX, mY + 1);
		cout << "|         \\\\_";
		GotoXY(mX, mY + 2);
		cout << "|____________|";
		GotoXY(mX, mY + 3);
		cout << "  ()-----()";
		TextColor(15);
	}
}