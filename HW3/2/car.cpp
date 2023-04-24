#include "car.h"

Car::Car(int num, string nam) : Vehicle(num, nam, "car") {}
void Car::describe() {
    cout << "A car with " << wh.get_num() << " wheels and a " << eng.get_name() << " engine.\n";
}