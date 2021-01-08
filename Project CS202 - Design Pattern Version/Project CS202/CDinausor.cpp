#include "CDinausor.h"

CDinausor::CDinausor() 
{
	CDisplay* disp = new CDinoDisplay;
	setDisplay(disp);
}

vector<vector<CPoint>> CDinausor::boundary(int pos_i) // For Impact
{
	vector<bool> bool_row;
	vector<vector<bool>> bool_boundary;
	string str;
	vector<string> strs;
	str = "          ";
	strs.push_back(str);
	str = "   (1*11_)";
	strs.push_back(str);
	str = "   |1111|/";
	strs.push_back(str);
	str = "  /|____|";
	strs.push_back(str);
	str = "    |_ |_";
	strs.push_back(str);

	/*cout << "   _____ ";
	GotoXY(mX, mY + 1);
	cout << "  ( *  _)";
	GotoXY(mX, mY + 2);
	cout << "  |    |/";
	GotoXY(mX, mY + 3);
	cout << " \\|____|";
	GotoXY(mX, mY + 4);
	cout << "   |_ |_";*/

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