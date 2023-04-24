#include "manager.h"

void Manager::newChef(const Chef &chef) {
    chefs.push_back(chef);
}
void Manager::order(const std::string &dish, int chefId) {
    if (chefId >= 0) {
        chefs[chefId].cook(dish);
    } else {
        for (auto chef : chefs) {
            if (chef.isSignatureDish(dish)) {
                chef.cook(dish);
                return;
            }
        }
        chefs[0].cook(dish);
    }
}