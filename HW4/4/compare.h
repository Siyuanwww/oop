#pragma once

#include "abstract_compare.h"
#include "point.h"

class CompareInt : public AbstractCompare<int> {
protected:
    int type_;
public:
    CompareInt(int _type) : type_(_type) {}
    int sum(int x);
    bool compare(int a, int b) override;
};

class ComparePoint : public AbstractCompare<Point> {
protected:
    int type_;
public:
    ComparePoint(int _type) : type_(_type) {}
    int dist(Point a);
    bool compare(Point a, Point b) override;
};


AbstractCompare<int>* get_compare_int(int type);
AbstractCompare<Point>* get_compare_point(int type);