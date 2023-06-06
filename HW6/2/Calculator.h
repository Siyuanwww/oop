#pragma once
#include "PerformStrategy.h"
#include "LevelStrategy.h"

class Calculator {
    LevelStrategy *m_levelStrategy;
    PerformStrategy *m_performStrategy;
public:
    Calculator(LevelStrategy *m_levelStrategy, PerformStrategy *m_performStrategy);
    int get_base();
    int get_total(int base);
};