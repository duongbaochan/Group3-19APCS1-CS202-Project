#include "CBird.h"

CBird::CBird(int x, int y) : CAnimal(x, y)
{

}
void CBird::draw()
{
	if (mX > 0 && mX < 85) {
		GotoXY(mX, mY);
		TextColor(6);
		cout << "  _/\\__";
		GotoXY(mX, mY + 1);
		cout << " /     \\__";
		GotoXY(mX, mY + 2);
		cout << " \\_____(__)";
		GotoXY(mX, mY + 3);
		cout << "   \\/      ";
		TextColor(15);
	}
}

// For Impact function
bool CBird::isDxAndDyInRange(int Dx, int Dy)
{
	if (Dy == 0)
		return (Dx >= 4 && Dx <= 5);
	if (Dy == 1)
		return (Dx >= 3 && Dx <= 7);
	if (Dy == 2)
		return (Dx >= 2 && Dx <= 10);
	if (Dy == 3)
		return (Dx >= 2 && Dx <= 11);
	if (Dy == 4)
		return (Dx >= 4 && Dx <= 5);
	return 0;
}