#pragma once

#include <iostream>
#include <string>

using namespace std;

class MilkTea
{
public:
    virtual string serve() = 0;
    virtual unsigned long long int price() = 0;
};


// Concrete Component   
class BaseMilkTea : public MilkTea
{
public:
    string serve();
    unsigned long long int price();
};

class MilkOnly : public MilkTea
{
public:
    string serve();
    unsigned long long int price();
};

class TeaOnly : public MilkTea
{
public:
    string serve();
    unsigned long long int price();
};

// Decorator  
class AddTopping : public MilkTea
{
protected:
    MilkTea* milk_tea;
public:
    AddTopping(MilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};


// Concrete Decorator  
class AddBubble : public AddTopping
{
public:
    AddBubble(MilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};


class AddBlackSugar : public AddTopping
{
public:
    AddBlackSugar(MilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};

class AddEggPudding : public AddTopping
{
public:
    AddEggPudding(MilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};

class AddFruitPudding : public AddTopping
{
public:
    AddFruitPudding(MilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};

class AddWhiteBubble : public AddTopping
{
public:
    AddWhiteBubble(MilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};