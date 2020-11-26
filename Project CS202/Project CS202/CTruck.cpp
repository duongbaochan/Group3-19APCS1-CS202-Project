#include "CTruck.h"

CTruck::CTruck(int x, int y) : CVehicle(x, y)
{

}
void CTruck::draw()
{
	GotoXY(mX, mY);
	if (mX > 0) cout << "Tr";
}
