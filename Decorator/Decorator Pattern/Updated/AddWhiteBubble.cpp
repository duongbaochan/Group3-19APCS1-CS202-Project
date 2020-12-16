#include "AddWhiteBubble.h"

//Concrete Decorator
AddWhiteBubble::AddWhiteBubble(MilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

string AddWhiteBubble::serve()
{
    return milk_tea->serve() + " + White Bubble";
}
unsigned long long int AddWhiteBubble::price()
{
    return milk_tea->price() + 7000;
}