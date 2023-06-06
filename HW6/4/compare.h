#include <functional>
template <class T>
class Compare {
public:
    std::vector<std::function<bool(T, T)>> vec;
    Compare() = default;
    Compare(std::initializer_list<std::function<bool(T, T)>> vec) : vec(vec) {}
    bool operator()(const T &x, const T &y) {
        for (auto comp : vec) {
            if (comp(x, y) || comp(y, x)) {
                return comp(x, y);
            }
        }
        return true;
    }
};