#include "AddFruitPudding.h"

//Concrete Decorator
AddFruitPudding::AddFruitPudding(MilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

string AddFruitPudding::serve()
{
    return milk_tea->serve() + " + Fruit Pudding";
}
unsigned long long int AddFruitPudding::price()
{
    return milk_tea->price() + 11000;
}