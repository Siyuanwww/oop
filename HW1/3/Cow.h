#include <string>
using namespace std;

class Cow {
public:
    string name;
    int l, u, m;
    Cow(const string &name, int l, int u, int m) : name(name), l(l), u(u), m(m) {}
};