#ifndef _ADD_WHITE_BUBBLE_H_
#define _ADD_WHITE_BUBBLE_H_

#include "AddTopping.h"

class AddWhiteBubble : public AddTopping
{
public:
    AddWhiteBubble(MilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};

#endif