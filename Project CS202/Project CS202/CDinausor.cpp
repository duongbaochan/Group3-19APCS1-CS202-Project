#include "CDinausor.h"

CDinausor::CDinausor(int x, int y) : CAnimal(x, y)
{

}
void CDinausor::draw()
{
	if (mX > 0 && mX<100) {
		GotoXY(mX, mY);
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
		TextColor(3);
		cout << "   _____ ";
		GotoXY(mX, mY + 1);
		cout << "  ( *  _)";
		GotoXY(mX, mY + 2);
		cout << "  |    |/";
		GotoXY(mX, mY + 3);
		cout << " \\|____|";
		GotoXY(mX, mY + 4);
		cout << "   |_ |_";
		TextColor(15);
	}
}
