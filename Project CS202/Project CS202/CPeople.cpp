#include "CPeople.h"

CPeople::CPeople()
{
	mX = mY = 0;
}
CPeople::CPeople(int w)
{
	mX = 50;
	mY = 0;
}

CPeople::CPeople(int mX, int mY)
{
	this->mX = mX;
	this->mY = mY;
}

void CPeople::setXY(int mX, int mY)
{
	this->mX = mX;
	this->mY = mY;
}

int CPeople::getX()
{
	return mX;
}

int CPeople::getY()
{
	return mY;
}

void CPeople::setX(int mX)
{
	this->mX = mX;
}
void CPeople::setY(int mY)
{
	this->mY = mY;
}

void CPeople::Up()
{
	mX -= step;
}
void CPeople::Left()
{
	mY -= step;
}
void CPeople::Right()
{
	mY += step;
}
void CPeople::Down()
{
	mX += step;
}

bool CPeople::isFinish()
{
	return mState;
}

bool CPeople::isDead()
{
	return mState;
}
bool CPeople::isImpact(CVehicle* x)
{
	vector<vector<COORD>> map = this->boundaryMap();
	vector<vector<COORD>> x_map = x->boundaryMap();
	COORD p;
	p.X = -1;
	p.Y = -1;

	for (int i = 0; i < map.size(); ++i)
		for (int j = 0; j < map[i].size(); ++j)
		{
			p = map[i][j];
			for (int x_i = 0; x_i < x_map.size(); ++x_i)
				for (int x_j = 0; x_j < x_map[x_i].size(); ++x_j)
				{
					if (x_map[x_i][x_j].X >= 0 && x_map[x_i][x_j].Y >= 0 && x_map[x_i][x_j].X == p.X && x_map[x_i][x_j].Y == p.Y)
					{
						PlaySound(TEXT("Sounds/woosh_2.wav"), NULL, SND_SYNC);
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
					if (map[i][j].X >= 0 && map[i][j].Y >= 0 && map[i][j].X == p.X && map[i][j].Y == p.Y)
					{
						PlaySound(TEXT("Sounds/woosh_2.wav"), NULL, SND_SYNC);
						return 1;
					}
				}
		}

	return 0;
}
bool CPeople::isImpact(CAnimal* x)
{
	vector<vector<COORD>> map = this->boundaryMap();
	vector<vector<COORD>> x_map = x->boundaryMap();
	COORD p;
	p.X = -1;
	p.Y = -1;

	for (int i = 0; i < map.size(); ++i)
		for (int j = 0; j < map[i].size(); ++j)
		{
			p = map[i][j];
			for (int x_i = 0; x_i < x_map.size(); ++x_i)
				for (int x_j = 0; x_j < x_map[x_i].size(); ++x_j)
				{
					if (x_map[x_i][x_j].X >= 0 && x_map[x_i][x_j].Y >= 0 && x_map[x_i][x_j].X == p.X && x_map[x_i][x_j].Y == p.Y)
					{
						PlaySound(TEXT("Sounds/woosh_1.wav"), NULL, SND_SYNC);
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
					if (map[i][j].X >= 0 && map[i][j].Y >= 0 && map[i][j].X == p.X && map[i][j].Y == p.Y)
					{
						PlaySound(TEXT("Sounds/woosh_1.wav"), NULL, SND_SYNC);
						return 1;
					}
				}
		}

	return 0;
}

void CPeople::draw()
{
    GotoXY(mX, mY);
    if (mX > 0 && mX < 85) {
        
		TextColor(7);
        cout << "  _  ";
        GotoXY(mX, mY + 1);
        cout << " (_) ";
        GotoXY(mX, mY + 2);
        cout << " -|-";
        GotoXY(mX, mY + 3);
        cout << " / \\";
        TextColor(15);
		
        //cout << "C" << endl;
		/*TextColor(243);
		cout << (char)223 << (char)223;
		TextColor(7);*/
	}
}

void CPeople::erase()
{
	GotoXY(mX, mY);
	cout << " " << " ";
	/*
	cout << "     ";
	GotoXY(mX, mY + 1);
	cout << "     ";
	GotoXY(mX, mY + 2);
	cout << "    ";
	GotoXY(mX, mY + 3);
	cout << "     ";
	*/
}

vector<vector<COORD>> CPeople::boundaryMap() // For Impact
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
