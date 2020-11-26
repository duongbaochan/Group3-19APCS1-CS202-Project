#include "CCar.h"

CCar::CCar(int x, int y) : CVehicle(x, y)
{

}
void CCar::draw()
{
	GotoXY(mX, mY);
	if (mX > 0) cout << "C";
}
