#include "operation.h"

class OperationNodeAdd : public OperationNodeTwo {
public:
    using OperationNodeTwo::OperationNodeTwo;
    void UpdateValue() override;
};