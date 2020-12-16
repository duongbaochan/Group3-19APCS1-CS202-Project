#ifndef _ADD_EGG_PUDDING_H_
#define _ADD_EGG_PUDDING_H_

#include "AddTopping.h"

class AddEggPudding : public AddTopping
{
public:
    AddEggPudding(MilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};

#endif