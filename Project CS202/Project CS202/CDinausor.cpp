#include "CDinausor.h"

CDinausor::CDinausor(int x, int y) : CAnimal(x, y)
{

}
void CDinausor::draw()
{
	GotoXY(mX, mY);
	if (mX > 0) cout << "D";
}
