#pragma once
#include "CDisplay.h"

class CObject
{
protected:
	vector <CPoint> pos;
	CDisplay* objDisp;
	bool objImpact;
public:
	//CObject(int, int);
//	CObject(CPoint);
	//~CObject();
	CObject();
	//CObject(const CObject &x);
	int getX(int i);
	int getY(int i);
	int size();
	virtual vector<vector<CPoint>> boundary(int);
	void setDisplay(CDisplay*);
//	bool isInRange(CPoint) const;
	void impact();
	void display(int, bool) const;
	void updatePos(int width, int speed);
	void addObject(int,int);
	void outputFile(ofstream& x);
	void inputFile(vector<int> tmp);
	int getPosTraffic();
	void loadFile(ifstream &x, int k);

};

