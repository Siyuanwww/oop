#include <cstdio>
#include <cassert>
template <typename T>
class my_ptr {
protected:
    T *p;
public:
    static T *null;
    my_ptr() : p(nullptr) {
        printf("my_ptr constructed.\n");
    }
    my_ptr(T *p) : p(p) {
        printf("my_ptr constructed.\n");
    }
    my_ptr(const T &data) : p(new T(data)) {
        printf("my_ptr constructed.\n");
    }
    my_ptr(const my_ptr &ptr) : p(nullptr) {
        printf("Copying of my_ptr is forbidden!\n");
        printf("my_ptr constructed.\n");
    }
    my_ptr(my_ptr &&ptr) {
        if (&ptr != this) {
            delete p;
            p = ptr.p;
            ptr.p = nullptr;
        }
        printf("my_ptr constructed.\n");
    }
    ~my_ptr() {
        printf("my_ptr destructed.\n");
        if (p) {
            delete p;
        }
    }
    my_ptr &operator=(const my_ptr &ptr) {
        printf("Copying of my_ptr is forbidden!\n");
        printf("my_ptr updated.\n");
        return *this;
    }
    my_ptr &operator=(my_ptr &&ptr) {
        if (&ptr != this) {
            delete p;
            p = ptr.p;
            ptr.p = nullptr;
        }
        printf("my_ptr updated.\n");
        return *this;
    }
    T *operator->() {
        if (p) {
            return p;
        } else {
            printf("Do not attempt to read a nullptr!\n");
            *null = T();
            return null;
        }
    }
    T &operator*() {
        if (p) {
            return *p;
        } else {
            printf("Do not attempt to read a nullptr!\n");
            *null = T();
            return *null;
        }
    }
};
template <typename T>
T *my_ptr<T>::null = new T();
