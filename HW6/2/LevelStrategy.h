#pragma once
class LevelStrategy {
public:
    virtual int get_base() = 0;
};
class P1LStrategy : public LevelStrategy {
public:
    int get_base() override;
};
class P2LStrategy : public LevelStrategy {
public:
    int get_base() override;
};
class P3LStrategy : public LevelStrategy {
public:
    int get_base() override;
};