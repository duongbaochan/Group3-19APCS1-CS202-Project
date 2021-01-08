#include "CBird.h"

CBird::CBird()
{
	CDisplay* disp = new CBirdDisplay;
	setDisplay(disp);
}

vector<vector<CPoint>> CBird::boundary(int pos_i) // For Impact
{
	vector<bool> bool_row;
	vector<vector<bool>> bool_boundary;
	string str;
	vector<string> strs;
	str = "   /\\  ";		// "  _/\\__";
	strs.push_back(str);
	str = " /  1  \\  ";	// " /     \\__"
	strs.push_back(str);
	str = " \\_____(__)";	// " \\_____(__)"
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

	vector<vector<CPoint>> boundary;
	vector<CPoint> row;
	CPoint p;
	for (int i = 0; i < bool_boundary.size(); ++i)
	{
		row.clear();
		for (int j = 0; j < bool_boundary[i].size(); ++j)
		{
			if (bool_boundary[i][j] == 1)
			{
				p.mX = this->getX(pos_i) + j;
				p.mY = this->getY(pos_i) + i;
				row.push_back(p);
			}
			else
			{
				p.mX = -1;
				p.mY = -1;
				row.push_back(p);
			}
		}
		boundary.push_back(row);
	}

	return boundary;
}