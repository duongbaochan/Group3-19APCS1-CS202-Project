#include "CBird.h"

CBird::CBird(int x, int y) : CAnimal(x, y)
{

}
void CBird::draw(int textColor, bool isDraw)
{
	if (!isDraw) return;
	if (mX > 0 && mX < 85) {
		GotoXY(mX, mY);
		TextColor(textColor);
		//TextColor(6);
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

vector<vector<COORD>> CBird::boundaryMap() // For Impact function
{
	vector<bool> bool_row;
	vector<vector<bool>> bool_boundary;
	string str;
	vector<string> strs;
	str = "   /\\  ";		// "  _/\\__";
	strs.push_back(str);
	str = " /     \\  ";	// " /     \\__"
	strs.push_back(str);
	str = " \\     (  )";	// " \\_____(__)"
	strs.push_back(str);
	str = "   \\/      ";
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