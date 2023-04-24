#include "minus.h"

void OperationNodeMinus::UpdateValue() {
    value_ = input1->value() - input2->value();
}