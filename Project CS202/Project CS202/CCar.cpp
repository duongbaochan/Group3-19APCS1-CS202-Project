#include "CCar.h"

CCar::CCar(int x, int y) : CVehicle(x, y)
{

}
void CCar::draw(int textColor, bool isDraw)
{
	if (!isDraw) return;
	GotoXY(mX, mY);
	if (mX > 0 && mX < 85) {
		TextColor(textColor);
		//TextColor(5);
		cout << "   _____";
		GotoXY(mX, mY + 1);
		cout << " _/     \\__";
		GotoXY(mX-1, mY + 2);
		cout << " |__________|";
		GotoXY(mX, mY + 3);
		cout << "  ()----()";
		TextColor(15);
		//cout << "C" << endl;
	}
}

vector<vector<COORD>> CCar::boundaryMap() // For Impact function
{
	vector<bool> bool_row;
	vector<vector<bool>> bool_boundary;
	string str;
	vector<string> strs;
	str = "   _____";
	strs.push_back(str);
	str = " _/     \\__";
	strs.push_back(str);
	str = "|__________|";
	strs.push_back(str);
	str = "  ()----()";
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