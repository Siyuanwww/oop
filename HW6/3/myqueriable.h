#include <vector>
#include <functional>

template <class T>
class MyQueriable {
public:
    std::vector<T> vec;
    int size() {
        return vec.size();
    }
    T &operator[](int k) {
        return vec[k];
    }
    template <class TT>
    MyQueriable where(TT f) {
        MyQueriable<T> ans;
        for (auto x : vec) {
            if (f(x)) {
                ans.vec.push_back(x);
            }
        }
        return ans;
    }
    template <class TT>
    MyQueriable apply(TT f) {
        MyQueriable<T> ans;
        for (auto x : vec) {
            ans.vec.push_back(f(x));
        }
        return ans;
    }
    T sum() {
        T ans = 0;
        for (auto x : vec) {
            ans += x;
        }
        return ans;
    }
};
template <class T>
MyQueriable<T> from(const std::vector<T> &vec) {
    MyQueriable<T> ans;
    ans.vec = vec;
    return ans;
}