#include "AddBubble.h"

// Concrete Decorator
AddBubble::AddBubble(MilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

string AddBubble::serve()
{
    return milk_tea->serve() + " + Bubble";
}

unsigned long long int AddBubble::price()
{
    return milk_tea->price() + 8000;
}