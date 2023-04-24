#include <vector>
#include "chef.h"

class Manager {
private:
    std::vector<Chef> chefs;
public:
    void newChef(const Chef &chef);
    void order(const std::string &dish, int chefId = -1);
};
