#include "CBird.h"

CBird::CBird(int x, int y) : CAnimal(x, y)
{

}
void CBird::draw()
{
	GotoXY(mX, mY);
	if (mX > 0) {
		cout << "  _/\\__";
		GotoXY(mX, mY + 1);
		cout << " /     \\__";
		GotoXY(mX, mY + 2);
		cout << " \\_____(__)";
		GotoXY(mX, mY + 3);
		cout << "   \\/      " << endl;
	}
}

