#ifndef _DUCK_H_
#define _DUCK_H_

#include "FlyBehavior.h"
#include "QuackBehavior.h"

using namespace std;

class Duck {
public:
	Duck();
	
	FlyBehavior* flyBehavior;
	QuackBehavior* quackBehavior;

	void setFlyBehavior(FlyBehavior* fly);
	void setQuackBehavior(QuackBehavior* quack);
	
	virtual void display() = 0;
	virtual void doFly() = 0;
	virtual void doQuack() = 0;
};

#endif