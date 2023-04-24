#include "Rack.h"
#include <algorithm>

Rack::Rack() {
    v.clear();
}
Rack &Rack::operator+=(int x) {
    v.push_back(x);
    return *this;
}
Rack &Rack::operator+=(Rack r) {
    for (auto x : r.v) {
        v.push_back(x);
    }
    return *this;
}
Rack operator,(Rack a, Rack b) {
    Rack ans = std::move(a);
    ans += b;
    return ans;
}
Rack operator,(Rack a, int x) {
    Rack ans = std::move(a);
    ans += x;
    return ans;
}
Rack operator,(int x, Rack a) {
    Rack ans;
    ans += x;
    ans += a;
    return ans;
}
std::ostream &operator<<(std::ostream &os, const Rack &r) {
    for (auto x : r.v) {
        os << ' ' << x;
    }
    return os;
}
int Rack::operator<(const Rack &r) const {
    return v.size() < r.v.size() ? 1 : 0;
}
int Rack::operator>(const Rack &r) const {
    return v.size() > r.v.size() ? 1 : 0;
}
int Rack::operator==(const Rack &r) const {
    return v.size() == r.v.size() ? 1 : 0;
}
bool appear(int y, const std::vector<int> &v) {
    for (auto x : v) {
        if (x == y) {
            return true;
        }
    }
    return false;
}
Rack Rack::operator&(const Rack &r) const {
    Rack ans;
    for (auto x : v) {
        if (!appear(x, ans.v) && appear(x, r.v)) {
            ans.v.push_back(x);
        }
    }
    return ans;
}
int Rack::operator()(int x) const {
    int ans = 0;
    for (auto t : v) {
        ans += t == x;
    }
    return ans;
}
Rack &Rack::operator~() {
    std::reverse(v.begin(), v.end());
    return *this;
}
Rack &Rack::operator--(int) {
    v.pop_back();
    return *this;
}
Rack &Rack::operator--() {
    v.erase(v.begin());
    return *this;
}