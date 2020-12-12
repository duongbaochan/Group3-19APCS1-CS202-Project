#include "function.h"

int main()
{
	MilkTea* base_milk_tea = new BaseMilkTea();
	cout << "Milk Tea #1 \n";
	cout << base_milk_tea->serve() << endl;
	cout << base_milk_tea->price() << endl;
	cout << endl;

	MilkTea* topping_added_milk_tea = new AddBubble(base_milk_tea);
	cout << "Milk Tea #2 \n";
	cout << topping_added_milk_tea->serve() << endl;
	cout << topping_added_milk_tea->price() << endl;
	cout << endl;

	delete topping_added_milk_tea;

	topping_added_milk_tea = new AddBlackSugar(base_milk_tea);
	cout << "Milk Tea #3 \n";
	cout << topping_added_milk_tea->serve() << endl;
	cout << topping_added_milk_tea->price() << endl;
	cout << endl;

	delete topping_added_milk_tea;
	delete base_milk_tea;

	return 0;
}