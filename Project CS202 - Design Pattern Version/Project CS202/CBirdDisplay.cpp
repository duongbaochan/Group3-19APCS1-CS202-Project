#include "CBirdDisplay.h"

void CBirdDisplay::display(CPoint x, bool isDraw, int textColor)
{
	if (!isDraw) return;
	if (x.mX > 0 && x.mX < 85) {
		GotoXY(x.mX, x.mY);
		TextColor(textColor);
		cout << "  _/\\__";
		GotoXY(x.mX, x.mY + 1);
		cout << " /     \\__";
		GotoXY(x.mX, x.mY + 2);
		cout << " \\_____(__)";
		GotoXY(x.mX, x.mY + 3);
		cout << "   \\/      ";
		TextColor(15);
	}
}