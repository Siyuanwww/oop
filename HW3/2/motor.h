#ifndef __VEHICLE_H__
#include "vehicle.h"
#endif

class Motor : public Vehicle {
public:
    Motor(int, string);
    void describe();
    void sell();
};