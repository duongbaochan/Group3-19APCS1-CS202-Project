#include <iostream>
#include "DecoyDuck.h"
#include "NoFly.h"
#include "NoQuack.h"

DecoyDuck::DecoyDuck() {
	cout << "I am Decoy!" << endl;

	flyBehavior = new NoFly();
	quackBehavior = new NoQuack();
}

void DecoyDuck::display() {
	cout << "I am a decoy duck!" << endl;
}

void DecoyDuck::doFly() {
	flyBehavior->fly();
}

void DecoyDuck::doQuack() {
	quackBehavior->quack();
}