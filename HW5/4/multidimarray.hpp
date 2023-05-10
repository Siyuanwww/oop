#include <vector>

template <typename T, int D>
struct MultiDimArray {
    std::vector<MultiDimArray<T, D - 1>> data;
    MultiDimArray(std::vector<int> dim) {
        int t = dim[0];
        dim.erase(dim.begin());
        data.assign(t, MultiDimArray<T, D - 1>(dim));
    }
    MultiDimArray<T, D - 1> &operator[](int x) {
        return data[x];
    }
};
template <typename T>
struct MultiDimArray<T, 1> {
    std::vector<T> data;
    MultiDimArray(std::vector<int> dim) {
        data.assign(dim[0], T(0));
    }
    T &operator[](int x) {
        return data[x];
    }
};
