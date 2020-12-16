#ifndef _ADD_TOPPING_H_
#define _ADD_TOPPING_H_

#include "MilkTea.h"

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

#endif