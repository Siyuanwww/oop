#pragma once

#include <cmath>

class Func{
public:
    Func() {}
    virtual double getPoint(double point)=0;
    virtual ~Func() {}
};