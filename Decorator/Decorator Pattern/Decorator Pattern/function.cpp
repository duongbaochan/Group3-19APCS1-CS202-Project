#include "function.h"

string MilkTea::serve()
{
    return 0;
}

int MilkTea::price()
{
    return 0;
}

// Concrete Component   
string BaseMilkTea::serve()
{
    return "Milk Tea";
}

int BaseMilkTea::price()
{
    return 50000;
}

string MilkOnly::serve()
{
    return "Milk";
}

int MilkOnly::price()
{
    return 25000;
}

string TeaOnly::serve()
{
    return "Tea";
}

int TeaOnly::price()
{
    return 25000;
}

// Decorator  
AddTopping::AddTopping(MilkTea* base_milk_tea) : milk_tea(base_milk_tea) {}

string AddTopping::serve()
{
    return milk_tea->serve();
}

int AddTopping::price()
{
    return milk_tea->price();
}

// Concrete Decorator
AddBubble::AddBubble(MilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

string AddBubble::serve()
{
    return milk_tea->serve() + " + Bubble";
}

int AddBubble::price()
{
    return milk_tea->price() + 8000;
}


AddBlackSugar::AddBlackSugar(MilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

string AddBlackSugar::serve()
{
    return milk_tea->serve() + " + Black Sugar";
}

int AddBlackSugar::price()
{
    return milk_tea->price() + 2000;
}

AddEggPudding::AddEggPudding(MilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

string AddEggPudding::serve()
{
    return milk_tea->serve() + " + Egg Pudding";
}

int AddEggPudding::price()
{
    return milk_tea->price() + 10000;
}

AddFruitPudding::AddFruitPudding(MilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

string AddFruitPudding::serve()
{
    return milk_tea->serve() + " + Fruit Pudding";
}
int AddFruitPudding::price()
{
    return milk_tea->price() + 11000;
}

AddWhiteBubble::AddWhiteBubble(MilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

string AddWhiteBubble::serve()
{
    return milk_tea->serve() + " + White Bubble";
}
int AddWhiteBubble::price()
{
    return milk_tea->price() + 7000;
}