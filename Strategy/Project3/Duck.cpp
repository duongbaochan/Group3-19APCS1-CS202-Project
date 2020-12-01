#include "Duck.h"

//Duck

Duck::Duck() {
	cout << "I am a duck! :D" << endl;
}

void Duck::setFlyBehavior(FlyBehavior* fly) {
	flyBehavior = fly;
}
void Duck::setQuackBehavior(QuackBehavior* quack) {
	quackBehavior = quack;
}
