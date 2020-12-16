#ifndef _ADD_FRUIT_PUDDING_H_
#define _ADD_FRUIT_PUDDING_H_

#include "AddTopping.h"

class AddFruitPudding : public AddTopping
{
public:
    AddFruitPudding(MilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};

#endif