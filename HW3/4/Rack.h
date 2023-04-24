#include <vector>
#include <iostream>

class Rack {
public:
    std::vector<int> v;
    Rack();
    Rack &operator+=(int);
    Rack &operator+=(Rack);
    friend Rack operator,(Rack, Rack);
    friend Rack operator,(Rack, int);
    friend Rack operator,(int, Rack);
    friend std::ostream &operator<<(std::ostream&, const Rack&);
    int operator<(const Rack&) const;
    int operator>(const Rack&) const;
    int operator==(const Rack&) const;
    Rack operator&(const Rack&) const;
    int operator()(int) const;
    Rack &operator~();
    Rack &operator--(int);
    Rack &operator--();
};