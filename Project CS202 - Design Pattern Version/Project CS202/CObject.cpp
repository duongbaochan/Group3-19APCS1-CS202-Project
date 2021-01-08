#include "CObject.h"

/*CObject::CObject(int x, int y)
{
	pos = new CPoint(x, y);
	objImpact = NULL;
	objDisp = NULL;
}
CObject::CObject(CPoint x)
{
	pos = new CPoint(x);
	objImpact = NULL;
	objDisp = NULL;
}
CObject::~CObject()
{
	delete pos;
	delete objDisp;
	delete objImpact;
}
CObject::CObject()
{
	pos = new CPoint(0, 0);
	objImpact = NULL;
	objDisp = NULL;
}*/
CObject::CObject()
{
	objImpact = NULL;
	objDisp = NULL;
}
int CObject::getX(int i)
{
	return pos[i].mX;
}
int CObject::getY(int i)
{
	return pos[i].mY;
}
int CObject::size()
{
	return pos.size();
}
vector<vector<CPoint>> CObject::boundary(int pos_i)
{
	CPoint p;
	p.mX = -1;
	p.mY = -1;
	return { {p} };
}

void CObject::setDisplay(CDisplay* x){
	objDisp = x;
}

void CObject::impact() 
{
	objImpact = 1;
	PlaySound(TEXT("Sounds/woosh_2.wav"), NULL, SND_SYNC);
}
void CObject::display(int textColor, bool isDraw) const {
	if (this->objDisp)
	{
		for (int i = 0; i < pos.size(); i++)
			this->objDisp->display(pos[i], isDraw, textColor);
	}
}
void CObject::updatePos(int width, int speed)
{
	for (int i = 0; i < pos.size(); i++)
	{
		pos[i].mX = pos[i].mX + speed;
		if (pos[i].mX >= 0)
			pos[i].mX %= width;
	}

}
void CObject::addObject(int x, int y)
{
	pos.push_back(CPoint(x,y));
}
void CObject::outputFile(ofstream& x)
{
	for (int i = 0; i < pos.size(); i++)
		x << pos[i].mX << "," << pos[i].mY << ",";
}
void CObject::inputFile(vector<int> tmp)
{
	int cur = 0;
	while (!tmp.empty())
	{
		int x = tmp.back();
		tmp.pop_back();
		int y = tmp.back();
		tmp.pop_back();
		addObject(x, y);
		cur++;
	}
}
int CObject::getPosTraffic()
{
	return pos[0].mY;
}
void CObject::loadFile(ifstream &x, int k)
{
	for (int i = 0; i < k; i++)
	{
		int mX, mY;
		x >> mX >> mY;
		pos.push_back(CPoint(mX, mY));
	}
}

