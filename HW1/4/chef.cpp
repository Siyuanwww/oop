#include "chef.h"

Chef::Chef(std::string _name, std::string _signatureDish) : name(_name), signatureDish(_signatureDish) {}
bool Chef::isSignatureDish(std::string dish) {
    return dish == signatureDish;
}
void Chef::cook(std::string dish) {
    printf("%s made %s %s\n", name.c_str(), isSignatureDish(dish) ? "an awesome" : "a plain", dish.c_str());
}