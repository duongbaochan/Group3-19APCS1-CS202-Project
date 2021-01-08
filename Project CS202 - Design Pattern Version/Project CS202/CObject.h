#pragma once
#include "CDisplay.h"

class CObject
{
protected:
	vector <CPoint> pos;
	CDisplay* objDisp;
	bool objImpact;
	int speed;
public:
	//CObject(int, int);
//	CObject(CPoint);
	//~CObject();
	CObject();
	//CObject(const CObject &x);
	int getX(int i);
	int getY(int i);
	int getSpeed();
	int size();
	virtual vector<vector<CPoint>> boundary(int);
	void setDisplay(CDisplay*);
//	bool isInRange(CPoint) const;
	void impact();
	void display(int, bool) const;
	void updatePos(int width, int speed);
	void addObject(int,int, int);
	void addObject(int, int);

	void updateSpeed();
	void outputFile(ofstream& x);
	//void inputFile(vector<int> tmp);
	int getPosTraffic();
	void loadFile(ifstream &x, int k, int _speed);

	void updatePosandDisp(int width, int speed, int textColor, bool isDraw);
};

