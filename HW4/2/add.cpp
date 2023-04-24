#include "add.h"

void OperationNodeAdd::UpdateValue() {
    value_ = input1->value() + input2->value();
}