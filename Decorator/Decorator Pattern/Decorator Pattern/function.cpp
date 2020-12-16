#include "function.h"


unsigned long long int BaseMilkTea::price()
{
    return 0;
}

// Concrete Component   
string MilkTea::serve()
{
    return "Milk Tea";
}

unsigned long long int MilkTea::price()
{
    return 30000;
}

string MilkOnly::serve()
{
    return "Milk";
}

unsigned long long int MilkOnly::price()
{
    return 20000;
}

string TeaOnly::serve()
{
    return "Tea";
}

unsigned long long int TeaOnly::price()
{
    return 20000;
}

// Decorator  
AddTopping::AddTopping(BaseMilkTea* base_milk_tea) : milk_tea(base_milk_tea) {}


// Concrete Decorator
AddBubble::AddBubble(BaseMilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

string AddBubble::serve()
{
    return milk_tea->serve() + " + Bubble";
}

unsigned long long int AddBubble::price()
{
    return milk_tea->price() + 5000;
}


AddBlackSugar::AddBlackSugar(BaseMilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

string AddBlackSugar::serve()
{
    return milk_tea->serve() + " + Black Sugar";
}

unsigned long long int AddBlackSugar::price()
{
    return milk_tea->price() + 15000;
}

AddEggPudding::AddEggPudding(BaseMilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

string AddEggPudding::serve()
{
    return milk_tea->serve() + " + Egg Pudding";
}

unsigned long long int AddEggPudding::price()
{
    return milk_tea->price() + 10000;
}

AddFruitPudding::AddFruitPudding(BaseMilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

string AddFruitPudding::serve()
{
    return milk_tea->serve() + " + Fruit Pudding";
}
unsigned long long int AddFruitPudding::price()
{
    return milk_tea->price() + 10000;
}

AddWhiteBubble::AddWhiteBubble(BaseMilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

string AddWhiteBubble::serve()
{
    return milk_tea->serve() + " + White Bubble";
}
unsigned long long int AddWhiteBubble::price()
{
    return milk_tea->price() + 5000;
}