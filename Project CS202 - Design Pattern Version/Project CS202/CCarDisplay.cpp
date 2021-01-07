#include ".h"

void CCarDisplay::display(CPoint)
{
	if (mX > 0 && mX < 85) {
		TextColor(textColor);
		//TextColor(5);
		cout << "   _____";
		GotoXY(mX, mY + 1);
		cout << " _/     \\__";
		GotoXY(mX - 1, mY + 2);
		cout << " |__________|";
		GotoXY(mX, mY + 3);
		cout << "  ()----()";
		TextColor(15);
		//cout << "C" << endl;
	}
}
