#include "CDinausor.h"

CDinausor::CDinausor(int x, int y) : CAnimal(x, y)
{

}
void CDinausor::draw(int textColor, bool isDraw)
{
	if (!isDraw) return;
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
		//TextColor(3);
		TextColor(textColor);
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

vector<vector<COORD>> CDinausor::boundaryMap() // For Impact function
{
	vector<bool> bool_row;
	vector<vector<bool>> bool_boundary;
	string str;
	vector<string> strs;
	str = "    _____ ";
	strs.push_back(str);
	str = "   ( *  _)";
	strs.push_back(str);
	str = "   |    |/";
	strs.push_back(str);
	str = "  /|____|";
	strs.push_back(str);
	str = "    |_ |_";
	strs.push_back(str);

	for (int i = 0; i < strs.size(); ++i)
	{
		bool_row.clear();
		for (int j = 0; j < strs[i].length(); ++j)
		{
			if (strs[i][j] == ' ')
				bool_row.push_back(0);
			else
				bool_row.push_back(1);
		}
		bool_boundary.push_back(bool_row);
	}

	vector<vector<COORD>> map;
	vector<COORD> row;
	COORD p;
	for (int i = 0; i < bool_boundary.size(); ++i)
	{
		row.clear();
		for (int j = 0; j < bool_boundary[i].size(); ++j)
		{
			if (bool_boundary[i][j] == 1)
			{
				p.X = mX + j;
				p.Y = mY + i;
				row.push_back(p);
			}
			else
			{
				p.X = -1;
				p.Y = -1;
				row.push_back(p);
			}
		}
		map.push_back(row);
	}

	return map;
}