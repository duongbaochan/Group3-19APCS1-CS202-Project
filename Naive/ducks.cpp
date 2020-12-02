#include "functions.h" 
#include "behavior.h"
#include "ducks.h"

//Default Duck
Duck::Duck() {
	cout << "Hello, I am Duck!" << endl;
}

void Duck::display() {
	cout << "I am also a duck" << endl;
}

//Mallard Duck
MallardDuck::MallardDuck() {
	cout << "Hello, I am Mallard!" << endl;
}

void MallardDuck::display() {
	cout << "I am also a Mallard duck" << endl;
}

//Red Head Duck
RedHeadDuck::RedHeadDuck() {
	cout << "Hello, I am Red Head!" << endl;
}

void RedHeadDuck::display() {
	cout << "I am also a Red Head duck" << endl;
}

//Rubber Duck
RubberDuck::RubberDuck() {
	cout << "Hello, I am Rubber!" << endl;
}

void RubberDuck::display() {
	cout << "I am also a rubber duck" << endl;
}

//Decoy Duck
DecoyDuck::DecoyDuck() {
	cout << "Hello, I am Decoy!" << endl;
}

void DecoyDuck::display() {
	cout << "I am also a decoy duck" << endl;
}