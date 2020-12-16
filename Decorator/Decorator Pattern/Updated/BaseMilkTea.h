#ifndef _BASE_MILK_TEA_H_
#define _BASE_MILK_TEA_H_

#include "MilkTea.h"

class BaseMilkTea : public MilkTea
{
public:
    string serve();
    unsigned long long int price();
};

#endif