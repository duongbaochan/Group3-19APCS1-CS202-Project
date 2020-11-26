#include "CBird.h"

CBird::CBird(int x, int y) : CAnimal(x, y)
{

}
void CBird::draw()
{
	GotoXY(mX, mY);
	if (mX > 0) cout << "B";
}

