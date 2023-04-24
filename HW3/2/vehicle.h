#define __VEHICLE_H__
#include "wheel.h"
#include "engine.h"

class Vehicle {
public:
    Engine eng;
    Wheel wh;
    Vehicle(int, string, string = "vehicle");
    void describe();
};