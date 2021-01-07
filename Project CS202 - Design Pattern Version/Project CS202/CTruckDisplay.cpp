#include "CTruckDisplay.h"

void CTruckDisplay::display(CPoint x, bool isDraw, int textColor)
{
	if (!isDraw) return;
	if (x.mX > 0 && x.mX < 85) {
		GotoXY(x.mX - 1, x.mY);
		TextColor(textColor);
		//TextColor(8);
		cout << " ___________";
		GotoXY(x.mX - 1, x.mY + 1);
		cout << " |         \\\\_";
		GotoXY(x.mX - 1, x.mY + 2);
		cout << " |____________|";
		GotoXY(x.mX, x.mY + 3);
		cout << "  ()-----()";
		TextColor(15);
	}
}