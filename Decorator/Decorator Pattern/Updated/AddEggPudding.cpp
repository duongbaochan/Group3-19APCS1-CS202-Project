#include "AddEggPudding.h"

//Concrete Decorator
AddEggPudding::AddEggPudding(MilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

string AddEggPudding::serve()
{
    return milk_tea->serve() + " + Egg Pudding";
}

unsigned long long int AddEggPudding::price()
{
    return milk_tea->price() + 10000;
}