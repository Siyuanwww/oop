#ifndef __VEHICLE_H__
#include "vehicle.h"
#endif

class Car : public Vehicle {
public:
    Car(int, string);
    void describe();
};