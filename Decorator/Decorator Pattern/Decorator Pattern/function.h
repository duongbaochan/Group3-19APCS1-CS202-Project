#pragma once

#include <iostream>
#include <string>

using namespace std;

class BaseMilkTea
{
public:
    virtual string serve() = 0;
    virtual unsigned long long int price() = 0;
};


// Concrete Component   
class MilkTea : public BaseMilkTea
{
public:
    string serve();
    unsigned long long int price();
};

class MilkOnly : public BaseMilkTea
{
public:
    string serve();
    unsigned long long int price();
};

class TeaOnly : public BaseMilkTea
{
public:
    string serve();
    unsigned long long int price();
};

// Decorator  
class AddTopping : public BaseMilkTea
{
protected:
    BaseMilkTea* milk_tea;
public:
    AddTopping(BaseMilkTea* base_milk_tea);
    virtual string serve() = 0;
    virtual unsigned long long int price()  =0;
};


// Concrete Decorator  
class AddBubble : public AddTopping
{
public:
    AddBubble(BaseMilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};


class AddBlackSugar : public AddTopping
{
public:
    AddBlackSugar(BaseMilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};

class AddEggPudding : public AddTopping
{
public:
    AddEggPudding(BaseMilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};

class AddFruitPudding : public AddTopping
{
public:
    AddFruitPudding(BaseMilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};

class AddWhiteBubble : public AddTopping
{
public:
    AddWhiteBubble(BaseMilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};