#include "function.h"

int main()
{
	cout << "------------INVOICE------------" << endl;
	cout << "Order #132" << endl;
	cout << "Date: 16/12/2020    Time: 18:53" << endl;
	cout << endl;

	int total = 0;

	BaseMilkTea* drink1 = new MilkTea();
	cout << "Drink #1 \n";
	cout << drink1->serve() << endl;
	cout << drink1->price() << endl;
	total += drink1->price();
	cout << endl;

	BaseMilkTea* drink2 = new MilkTea();
	drink2 = new AddBubble(drink2);
	drink2 = new AddWhiteBubble(drink2);
	cout << "Drink #2 \n";
	cout << drink2->serve() << endl;
	cout << drink2->price() << endl;
	total += drink2->price();
	cout << endl;

	BaseMilkTea* drink3 = new MilkOnly();
	drink3 = new AddFruitPudding(drink3);
	drink3 = new AddBubble(drink3);
	cout << "Drink #3 \n";
	cout << drink3->serve() << endl;
	cout << drink3->price() << endl;
	total += drink3->price();
	cout << endl;

	delete[]drink1;
	delete[]drink2;
	delete[]drink3;

	cout << "TOTAL:" << endl;
	cout << total << endl;
	cout << "Amount Paid:" << endl;
	cout << 150000 << endl;
	cout << "Refund:" << endl;
	cout << 150000 - total << endl;
	cout << "---------SEE YOU AGAIN---------" << endl;

	return 0;
}