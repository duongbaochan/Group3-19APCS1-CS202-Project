#pragma once

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//Under Coding

void menu();

class PlainGrilledRiceCracker
{
protected:
	int price;
};

class GrilledRiceCracker : public PlainGrilledRiceCracker
{
public:
	void increase(int price);
};

class Topping
{
protected:
	int price;
public:
	virtual void increase(int price);
};
