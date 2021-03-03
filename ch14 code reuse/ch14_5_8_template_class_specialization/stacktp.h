#ifndef STACKTP_H_
#define STACKTP_H_
#include "iostream"
using std::cin;
using std::cout;
using std::endl;

template <class Tp1>
class Person {
    public:
        Tp1 entry;
        void Say(Tp1 word) {
            cout << "Hello base:" << word << endl;
        }
};

template class Person<int>; // 显示实例化一个模板

template <> class Person <char *> { // 显示具体化一个模板，为特殊类型实例化，对模板进行修改，使其行为不同
    public:
        char * entry;
        void Say(char * word) {
            cout << "Hello different:" << word << endl;
        }
};

template <class T1, class T2>
class Car {
    public:
        T1 speed;
        T2 brand;
        void Say(T1 spd, T2 brand) {
            cout << "The car say:" << spd << "-" << brand << endl;
        }
};

template <class T1>
class Car <T1, char *> {
    public:
        T1 speed;
        char * brand;
        void Say(T1 spd, char * brand) {
            cout << "The car say different:" << spd << "-" << brand << endl;
        }
};

#endif