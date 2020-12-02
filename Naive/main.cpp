#include "behavior.h"
#include "ducks.h" 
#include "functions.h"

int main() {
	MallardDuck mallard;
	mallard.display();
	mallard.fly();
	mallard.quack();
	
	cout << endl;

	RedHeadDuck redhead;
	redhead.display();
	redhead.fly();
	redhead.quack();

	cout << endl;

	RubberDuck rubber;
	rubber.display();
	rubber.quack();

	cout << endl;

	DecoyDuck decoy;
	decoy.display();
	return 0;
}