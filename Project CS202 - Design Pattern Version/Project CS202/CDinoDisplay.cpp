#include "CDinoDisplay.h"

void CDinoDisplay::display(CPoint x, bool isDraw, int textColor)
{
	if (!isDraw) return;
	if (x.mX > 0 && x.mX < 100) {
		GotoXY(x.mX, x.mY);
		/* DUNG XOA NHA, MOT CO DU`NG THI DU`NG CHU LO VE NAY CUC LAM :(
		cout << "      ******* ";
		GotoXY(mX, mY + 1);
		cout << "     **  *****";
		GotoXY(mX, mY + 2);
		cout << "     *********";
		GotoXY(mX, mY + 3);
		cout << "     ***      ";
		GotoXY(mX, mY+4);
		cout << "     *******  ";
		GotoXY(mX, mY+5);
		cout << "*   *****    ";
		GotoXY(mX, mY+6);
		cout << "** ********* ";
		GotoXY(mX, mY+7);
		cout << " ************";
		GotoXY(mX, mY+8);
		cout << "   ********* ";
		GotoXY(mX, mY+9);
		cout << "    **   **   ";
		GotoXY(mX, mY+10);
		cout << "    ***  ***  " << endl;
		*/
		//TextColor(3);
		TextColor(textColor);
		cout << "   _____ ";
		GotoXY(x.mX, x.mY + 1);
		cout << "  ( *  _)";
		GotoXY(x.mX, x.mY + 2);
		cout << "  |    |/";
		GotoXY(x.mX, x.mY + 3);
		cout << " \\|____|";
		GotoXY(x.mX, x.mY + 4);
		cout << "   |_ |_";
		TextColor(15);
	}
}