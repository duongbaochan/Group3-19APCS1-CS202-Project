#ifndef _mallard_duck_h_
#define _mallard_duck_h_

#include "Duck.h"

class MallardDuck : public Duck {
public:
	MallardDuck();

	void display();
	void doFly();
	void doQuack();
};

#endif