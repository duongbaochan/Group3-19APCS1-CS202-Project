#include "MilkTea.h"

int main()
{
	cout << "------------INVOICE------------" << endl;
	cout << "Order #132" << endl;
	cout << "Date: 14/12/2020    Time: 18:53" << endl;
	cout << endl;

	int total = 0;

	MilkTea* base_milk_tea = new BaseMilkTea();
	cout << "Drink #1 \n";
	cout << base_milk_tea->serve() << endl;
	cout << base_milk_tea->price() << endl;
	total += base_milk_tea->price();
	cout << endl;

	MilkTea* topping_added_milk_tea = new AddBubble(base_milk_tea);
	cout << "Drink #2 \n";
	cout << topping_added_milk_tea->serve() << endl;
	cout << topping_added_milk_tea->price() << endl;
	total += topping_added_milk_tea->price();
	cout << endl;

	delete topping_added_milk_tea;
	delete base_milk_tea;

	MilkTea* milk = new MilkOnly();
	topping_added_milk_tea = new AddFruitPudding(milk);
	cout << "Drink #3 \n";
	cout << topping_added_milk_tea->serve() << endl;
	cout << topping_added_milk_tea->price() << endl;
	total += topping_added_milk_tea->price();
	cout << endl;

	delete topping_added_milk_tea;
	delete milk;

	cout << "TOTAL:" << endl;
	cout << total << endl;
	cout << "Amount Paid:" << endl;
	cout << 150000 << endl;
	cout << "Refund:" << endl;
	cout << 150000 - total << endl;
	cout << "---------SEE YOU AGAIN---------" << endl;

	return 0;
}