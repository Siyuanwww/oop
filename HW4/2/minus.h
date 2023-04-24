#include "operation.h"

class OperationNodeMinus : public OperationNodeTwo {
public:
    using OperationNodeTwo::OperationNodeTwo;
    void UpdateValue() override;
};