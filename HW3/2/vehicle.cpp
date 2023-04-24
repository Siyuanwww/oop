#ifndef __VEHICLE_H__
#include "vehicle.h"
#endif

Vehicle::Vehicle(int num, string nam, string type) : eng(nam), wh(num) {
    cout << "Finish building a "<< type << " with " << num << " wheels and a " << nam << " engine.\n";
}
void Vehicle::describe() {
    cout << "A vehicle with " << wh.get_num() << " wheels and a " << eng.get_name() << " engine.\n";
}