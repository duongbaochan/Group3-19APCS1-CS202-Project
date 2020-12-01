#include <iostream>
#include "MallardDuck.h"
#include "Fly.h"
#include "Quack.h"

MallardDuck::MallardDuck() {
	cout << "I am Mallard!" << endl;

	flyBehavior = new Fly();
	quackBehavior = new Quack();
}

void MallardDuck::display() {
	cout << "I am a Mallard duck!" << endl;
}

void MallardDuck::doFly(){
	flyBehavior->fly();
}

void MallardDuck::doQuack() {
	quackBehavior->quack();
}