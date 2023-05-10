#pragma once

#include "func.h"

class CombFunc : public Func{
private:
    Func *f, *g;
    double a, b;
public:
    CombFunc(Func *fun_1, Func *fun_2, double coe_1, double coe_2) : f(fun_1), g(fun_2), a(coe_1), b(coe_2) {}
    ~CombFunc() {
        delete f;
        delete g;
    }
    double getPoint(double point) override {
        return a * f->getPoint(point) + b * g->getPoint(point);
    }
};