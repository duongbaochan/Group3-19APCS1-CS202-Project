#ifndef _ADD_BUBBLE_H_
#define _ADD_BUBBLE_H_

#include "AddTopping.h"

class AddBubble : public AddTopping
{
public:
    AddBubble(MilkTea* base_milk_tea);
    string serve();
    unsigned long long int price();
};

#endif