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





void CPeople::Up()
{
	pos.mY -= step;
}
void CPeople::Left()
{
	pos.mX -= step;
}
void CPeople::Right()
{
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
	return mState;
}
bool CPeople::isImpact(const CObject &x) const
{
	if (x.isInRange(pos))
	{
		return 1;
	}
	return 0;
}

void CPeople::draw()
{
    GotoXY(pos.mX, pos.mY);
    if (pos.mX > 0 && pos.mX < 85) {
        /*
		TextColor(7);
        cout << "  _  ";
        GotoXY(mX, mY + 1);
        cout << " (_) ";
        GotoXY(mX, mY + 2);
        cout << " -|-";
        GotoXY(mX, mY + 3);
        cout << " / \\";
        TextColor(15);
		*/
        //cout << "C" << endl;
		TextColor(243);
		cout << (char)223 << (char)223;
		TextColor(7);
	}
}
void CPeople::setmState(int x)
{
	mState = x;
}

void CPeople::erase()
{
	GotoXY(pos.mX, pos.mY);
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
