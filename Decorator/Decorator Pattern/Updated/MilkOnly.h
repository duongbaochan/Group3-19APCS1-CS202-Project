#ifndef _MILK_ONLY_H_
#define _MILK_ONLY_H_

#include "MilkTea.h"

class MilkOnly : public MilkTea
{
public:
    string serve();
    unsigned long long int price();
};

#endif