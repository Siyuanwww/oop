#pragma once

#include "func.h"

class LinearFunc : public Func{
private:
    double a, b;
public:
    LinearFunc(double a, double b) : a(a), b(b) {}
    double getPoint(double point) override {
        return a * point + b;
    }
};