#pragma once

#include "behavior.h" 
#include "functions.h"

class MallardDuck : public Duck, public SetFly, public SetQuack {
private:
	string name = "Mallard";

public: 
	MallardDuck();

	void display();
};

class RedHeadDuck : public Duck, public SetFly, public SetQuack {
private:
	string name = "Red Head";

public:
	RedHeadDuck();

	void display();
};

class RubberDuck : public Duck, public SetQuack {
private:
	string name = "Rubber";

public:
	RubberDuck();

	void display();
};

class DecoyDuck : public Duck {
private:
	string name = "Decoy";

public:
	DecoyDuck();

	void display();
};