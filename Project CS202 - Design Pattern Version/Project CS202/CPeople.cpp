#include "CPeople.h"

CPeople::CPeople()
{
	pos.mX = pos.mY = 0;
}
CPeople::CPeople(int w)
{
	pos.mX = w/2;
	pos.mY = 0;
}

CPeople::CPeople(int mX, int mY)
{
	pos.mX = mX;
	pos.mY = mY;
}

void CPeople::setXY(int mX, int mY)
{
	pos.mX = mX;
	pos.mY = mY;
}

int CPeople::getX()
{
	return pos.mX;
}
int CPeople::getY()
{
	return pos.mY;
}

vector<vector<CPoint>> CPeople::boundary() // For Impact
{
	vector<bool> bool_row;
	vector<vector<bool>> bool_boundary;
	string str;
	vector<string> strs;
	str = "  _  ";
	strs.push_back(str);
	str = " (_) ";
	strs.push_back(str);
	str = " -|-";
	strs.push_back(str);
	str = " / \\";
	strs.push_back(str);

	/*cout << "  _  ";
	GotoXY(mX, mY + 1);
	cout << " (_) ";
	GotoXY(mX, mY + 2);
	cout << " -|-";
	GotoXY(mX, mY + 3);
	cout << " / \\";*/

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
				p.mX = this->getX() + j;
				p.mY = this->getY() + i;
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


void CPeople::Up()
{
	pos.mY -= step;
}
void CPeople::Left()
{
	if (pos.mX>=4)
		pos.mX -= step;
}
void CPeople::Right()
{
	if (pos.mX <= 97)
		pos.mX += step;
}
void CPeople::Down()
{
	pos.mY += step;
}

bool CPeople::isFinish()
{
	return mState;
}

bool CPeople::isDead()
{
	return !mState;
}
bool CPeople::isImpact(CObject &x)
{
	for (int pos_i = 0; pos_i < x.size(); ++pos_i)
	{
		vector<vector<CPoint>> map = this->boundary();
		vector<vector<CPoint>> x_map = x.boundary(pos_i);
		CPoint p;
		p.mX = -1;
		p.mY = -1;

		for (int i = 0; i < map.size(); ++i)
			for (int j = 0; j < map[i].size(); ++j)
			{
				p = map[i][j];
				for (int x_i = 0; x_i < x_map.size(); ++x_i)
					for (int x_j = 0; x_j < x_map[x_i].size(); ++x_j)
					{
						if (x_map[x_i][x_j].mX >= 0 && x_map[x_i][x_j].mY >= 0 && x_map[x_i][x_j].mX == p.mX && x_map[x_i][x_j].mY == p.mY)
						{
							x.impact();
							return 1;
						}
					}
			}

		for (int x_i = 0; x_i < x_map.size(); ++x_i)
			for (int x_j = 0; x_j < x_map[x_i].size(); ++x_j)
			{
				p = x_map[x_i][x_j];
				for (int i = 0; i < map.size(); ++i)
					for (int j = 0; j < map[i].size(); ++j)
					{
						if (map[i][j].mX >= 0 && map[i][j].mY >= 0 && map[i][j].mX == p.mX && map[i][j].mY == p.mY)
						{
							x.impact();
							return 1;
						}
					}
			}
	}
	return 0;
}

void CPeople::draw()
{
    if (pos.mX > 0 && pos.mX <= 98) {
		GotoXY(pos.mX, pos.mY);
        
		TextColor(7);
        cout << "  _  ";
		GotoXY(pos.mX, pos.mY + 1);
        cout << " (_) ";
		GotoXY(pos.mX, pos.mY + 2);
		cout << " -|-";
		GotoXY(pos.mX, pos.mY + 3);
		cout << " / \\";
        TextColor(15);
		
        //cout << "C" << endl;
		/*TextColor(243);
		cout << (char)223 << (char)223;
		TextColor(7);*/
	}
}
void CPeople::setmState(int x)
{
	mState = x;
}

void CPeople::erase()
{
	GotoXY(pos.mX, pos.mY);
	/*cout << " " << " ";*/
	cout << "     ";
	GotoXY(pos.mX, pos.mY + 1);
	cout << "     ";
	GotoXY(pos.mX, pos.mY + 2);
	cout << "    ";
	GotoXY(pos.mX, pos.mY + 3);
	cout << "     ";
}

