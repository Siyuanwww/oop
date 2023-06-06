#pragma once
class PerformStrategy {
protected:
    double perform;
public:
    PerformStrategy(double perform);
    virtual int get_bonus(int base) = 0;
};
class sPerformStrategy : public PerformStrategy {
public:
    sPerformStrategy(double perform);
    int get_bonus(int base) override;
};
class mPerformStrategy : public PerformStrategy {
public:
    mPerformStrategy(double perform);
    int get_bonus(int base) override;
};
class lPerformStrategy : public PerformStrategy {
public:
    lPerformStrategy(double perform);
    int get_bonus(int base) override;
};