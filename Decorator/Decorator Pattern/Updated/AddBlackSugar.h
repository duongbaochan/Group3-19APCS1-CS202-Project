#ifndef _ADD_BLACK_SUGAR_H_
#define _ADD_BLACK_SUGAR_H_

#include "AddTopping.h"

class AddBlackSugar : public AddTopping
{
public:
    AddBlackSugar(MilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};

#endif