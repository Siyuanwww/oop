#include<iostream>
using namespace std;


class Appearance {
    int weight = 0;
public:
    Appearance(){
        cout<<"Appearance()\n";
    }
    Appearance(int _w):weight(_w){cout<<"Appearance(_w)\n";}
    ~Appearance(){}
};

class Small{
protected:
    Appearance A;
};

class Animal {
protected:
    Appearance A;
public:
    Animal(){cout<<"Animal()\n";} // (1)
    Animal(int _w){cout<<"Animal("<< _w << ")\n";A = Appearance(_w);} // (2)
    ~Animal(){}
};

class Rabbit: public Animal { // (3)
    Animal N{1};
public:
    Rabbit(){
        cout << "Rabbit()\n";
    }
    Appearance getA() {return A;}
    ~Rabbit(){}
};

int main() {
    Rabbit R;
    return 0;
}
/*
A. Appearance一共被实例化了2次。

B. R不可以访问数据成员N的Appearance

C. (1)、(2)分别被执行了1次，且(1)被先执行y

D. 如果将(3)改为class Rabbit: public Animal, public Small {，程序仍能通过编译，且输出没有变化

*/