#pragma once

#include <iostream>
#include <string>
//#include <sstream>

using namespace std;

//void menu();

class MilkTea
{
public:
    virtual string serve() = 0;
    virtual int price() = 0;
};


// Concrete Component   
class BaseMilkTea : public MilkTea
{
public:
    string serve()
    {
        return "Milk Tea";
    }

    int price()
    {
        return 50000;
    }
};

// Decorator  
class AddTopping : public MilkTea
{
protected:
    MilkTea* milk_tea;
public:

    AddTopping(MilkTea* base_milk_tea) : milk_tea(base_milk_tea) {}

    string serve()
    {
        return milk_tea->serve();
    }

    int price()
    {
        return milk_tea->price();
    }
};


// Concrete Decorator  
class AddBubble : public AddTopping
{
public:
    AddBubble(MilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

    string serve()
    {
        return milk_tea->serve() + " + Bubble";
    }
    int price()
    {
        return milk_tea->price() + 8000;
    }
};


class AddBlackSugar : public AddTopping
{
public:
    AddBlackSugar(MilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

    string serve()
    {
        return milk_tea->serve() + " + Black Sugar";
    }
    int price()
    {
        return milk_tea->price() + 2000;
    }
};

class AddEggPudding : public AddTopping
{
public:
    AddEggPudding(MilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

    string serve()
    {
        return milk_tea->serve() + " + Egg Pudding";
    }
    int price()
    {
        return milk_tea->price() + 10000;
    }
};

class AddFruitPudding : public AddTopping
{
public:
    AddFruitPudding(MilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

    string serve()
    {
        return milk_tea->serve() + " + Fruit Pudding";
    }
    int price()
    {
        return milk_tea->price() + 11000;
    }
};

class AddWhiteBubble : public AddTopping
{
public:
    AddWhiteBubble(MilkTea* base_milk_tea) : AddTopping(base_milk_tea) {}

    string serve()
    {
        return milk_tea->serve() + " + White Bubble";
    }
    int price()
    {
        return milk_tea->price() + 7000;
    }
};