#include <iostream>
#include <list>
#include <vector>
#include "compare.h"
#include "sortlevel.h"
using namespace std;

Compare<vector<int>> make_comp(list<sort_level> sortlevels) {
    Compare<std::vector<int>> comps;
    for (auto level : sortlevels) {
        if (level.order == ASCEND) {
            comps.vec.push_back([level](std::vector<int> x, std::vector<int> y) {
                return x[level.column - 1] < y[level.column - 1];
            });
        } else {
            comps.vec.push_back([level](std::vector<int> x, std::vector<int> y) {
                return x[level.column - 1] > y[level.column - 1];
            });
        }
    }
    return comps;
}
