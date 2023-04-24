#include "motor.h"

Motor::Motor(int num, string nam) : Vehicle(num, nam, "motor") {}
void Motor::describe() {
    cout << "A motor with " << wh.get_num() << " wheels and a " << eng.get_name() << " engine.\n";
}
void Motor::sell() {
    cout << "A motor is sold!\n";
}