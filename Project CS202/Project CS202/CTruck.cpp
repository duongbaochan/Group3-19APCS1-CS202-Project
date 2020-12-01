#include "CTruck.h"

CTruck::CTruck(int x, int y) : CVehicle(x, y)
{

}
void CTruck::draw()
{
	GotoXY(mX, mY);
	if (mX > 0) {
		cout << "___________" << endl;
		GotoXY(mX, mY + 1);
		cout << "|         \\\\_" << endl;
		GotoXY(mX, mY + 2);
		cout << "|____________|" << endl;
		GotoXY(mX, mY + 3);
		cout << "  ()-----()" << endl;
	}
}
