#include "CBird.h"

CBird::CBird(int x, int y) : CAnimal(x, y)
{

}
void CBird::draw()
{
	GotoXY(mX, mY);
	if (mX > 0) {
		//cout << "  __/_\\__" << endl;
		//cout << " /       \\___" << endl;
		//cout << "\\________(__)" << endl;
		//cout << "    \\/       " << endl;
		cout << "B";

	}
}

