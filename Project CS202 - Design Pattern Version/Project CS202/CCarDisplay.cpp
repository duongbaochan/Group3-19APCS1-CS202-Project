#include "CCarDisplay.h"

void CCarDisplay::display(CPoint x, bool isDraw, int textColor)
{
	if (x.mX > 0 && x.mX < 85) {
		TextColor(textColor);
		//TextColor(5);
		cout << "   _____";
		GotoXY(x.mX, x.mY + 1);
		cout << " _/     \\__";
		GotoXY(x.mX - 1, x.mY + 2);
		cout << " |__________|";
		GotoXY(x.mX, x.mY + 3);
		cout << "  ()----()";
		TextColor(15);
	}
}
