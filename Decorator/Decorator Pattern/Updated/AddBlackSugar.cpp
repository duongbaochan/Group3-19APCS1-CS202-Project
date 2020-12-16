#include "AddBlackSugar.h"

//Concrete Decorator
AddBlackSugar::AddBlackSugar(MilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

string AddBlackSugar::serve()
{
    return milk_tea->serve() + " + Black Sugar";
}

unsigned long long int AddBlackSugar::price()
{
    return milk_tea->price() + 2000;
}