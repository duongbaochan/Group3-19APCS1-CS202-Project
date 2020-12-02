#pragma once

#include "Duck.h"

class DecoyDuck : public Duck {
public:
	DecoyDuck();

	void display();
	void doFly();
	void doQuack();
};