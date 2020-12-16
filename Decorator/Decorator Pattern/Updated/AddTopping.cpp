#include "AddTopping.h"

AddTopping::AddTopping(MilkTea* base_milk_tea) : milk_tea(base_milk_tea) {}

string AddTopping::serve()
{
    return milk_tea->serve();
}

unsigned long long int AddTopping::price()
{
    return milk_tea->price();
}