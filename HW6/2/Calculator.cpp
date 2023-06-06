#include "Calculator.h"

Calculator::Calculator(LevelStrategy *m_levelStrategy, PerformStrategy *m_performStrategy) :
    m_levelStrategy(m_levelStrategy), m_performStrategy(m_performStrategy) {}
int Calculator::get_base() {
    return m_levelStrategy->get_base();
}
int Calculator::get_total(int base) {
    return base + m_performStrategy->get_bonus(base);
}