#include "PerformStrategy.h"

PerformStrategy::PerformStrategy(double perform) : perform(perform) {}
sPerformStrategy::sPerformStrategy(double perform) : PerformStrategy(perform) {}
mPerformStrategy::mPerformStrategy(double perform) : PerformStrategy(perform) {}
lPerformStrategy::lPerformStrategy(double perform) : PerformStrategy(perform) {}

int sPerformStrategy::get_bonus(int base) {
    return 1000;
}
int mPerformStrategy::get_bonus(int base) {
    return (int)(perform * base);
}
int lPerformStrategy::get_bonus(int base) {
    return (int)(2 * perform * base);
}