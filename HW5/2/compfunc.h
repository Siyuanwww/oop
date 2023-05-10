#pragma once

#include "func.h"

class CompFunc : public Func{
private:
    Func *f, *g;
public:
    CompFunc(Func *outer, Func* inner) : f(outer), g(inner) {}
    ~CompFunc() {
        delete f;
        delete g;
    }
    double getPoint(double point) override {
        return f->getPoint(g->getPoint(point));
    }
};