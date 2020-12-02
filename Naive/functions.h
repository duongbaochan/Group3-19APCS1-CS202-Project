#pragma once

#include <iostream>
#include <string>
#include ""

using namespace std;

class Duck {
private: 
	string name = "Duck";
	string sound = "Quack";

public:
	Duck();

	virtual void display();
	virtual void setFlyBehavior() {};
	virtual void doFlyBehavior() {};
};