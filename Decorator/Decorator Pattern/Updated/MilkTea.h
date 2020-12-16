#ifndef _MILK_TEA_H_
#define _MILK_TEA_H_

#include <iostream>
#include <string>

using namespace std;

class MilkTea
{
public:
    virtual string serve() = 0;
    virtual unsigned long long int price() = 0;
};

#endif