#include "CCar.h"

CCar::CCar(int x, int y) : CVehicle(x, y)
{

}
void CCar::draw()
{
	GotoXY(mX, mY);
	if (mX > 0) {
		cout << "   _____";
		GotoXY(mX, mY + 1);
		cout << " _/     \\__";
		GotoXY(mX, mY + 2);
		cout << "|__________|";
		GotoXY(mX, mY + 3);
		cout << "  ()----()";
		//cout << "C" << endl;
	}
}
