#ifndef _TEA_ONLY_H_
#define _TEA_ONLY_H_

#include "MilkTea.h"

class TeaOnly : public MilkTea
{
public:
    string serve();
    unsigned long long int price();
};

#endif