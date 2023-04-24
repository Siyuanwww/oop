#include <iostream>

class MyClass {
public:
    int operator()(int arg) const {
        return arg * arg;
    }
    
    template <typename... Args>
    int operator()(Args... args) const {
        int sum = 0;
        int temp[] = { (sum += args, 0)... };
        (void)temp;
        return sum;
    }
};

int main() {
    MyClass obj;
    std::cout << (1, 2, 3) << std::endl; // 输出6
    std::cout << obj(1, 2, 3) << std::endl; // 输出6
    return 0;
}
