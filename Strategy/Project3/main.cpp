#include <iostream>
#include <string>
#include "Duck.h"
#include "MallardDuck.h"
#include "DecoyDuck.h"
#include "Fly.h"
#include "NoFly.h"
#include "Quack.h"
#include "NoQuack.h"

int main() {
	//Mallard Duck Test
	cout << "==MALLARD DUCK TESTING==" << endl;
	Duck *mallard = new MallardDuck();
	mallard->display();
	mallard->doFly();
	mallard->doQuack();

	//Oh no, Mallard is shot by evil hunter! Set his Fly() to NoFly()
	FlyBehavior* noFly = new NoFly();
	mallard->setFlyBehavior(noFly);
	mallard->doFly();

	//He landed the ground with his beak, he is not able to quack now! Set his Quack() to NoQuack()
	QuackBehavior* noQuack = new NoQuack();
	mallard->setQuackBehavior(noQuack);
	mallard->doQuack();

	cout << endl;

	//Decoy Duck Test
	cout << "==DECOY DUCK TESTING==" << endl;
	Duck* decoy = new DecoyDuck();
	decoy->display();
	decoy->doFly();
	decoy->doQuack();

	//Our Decoy is equiped new wing engines, and now he can fly! Set his NoFly() to Fly()
	FlyBehavior* fly = new Fly();
	decoy->setFlyBehavior(fly);
	decoy->doFly();

	//He also has ability to quack like a robot. Set his NoQuack() to Quack()
	QuackBehavior* quack = new Quack();
	decoy->setQuackBehavior(quack);
	decoy->doQuack();

	return 0;
}