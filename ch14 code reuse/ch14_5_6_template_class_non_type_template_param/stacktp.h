#ifndef STACKTP_H_
#define STACKTP_H_

#include <iostream>
#include <cstdlib>

template <class Tp1, int n> // 模板的非类型参数

class ArrayTp {
    private:
        Tp1 ar[n];
    public:
        ArrayTp() {};
        explicit ArrayTp(const Tp1 &v);
        virtual Tp1 & operator[](int i);
        virtual Tp1 operator[](int i) const;
};


template <class Tp1, int n>
ArrayTp<Tp1,n>::ArrayTp(const Tp1 & v) {
    for (int i = 0; i < n; i++) {
        ar[i] = v;
    }
}
template <class Tp1, int n>
Tp1 & ArrayTp<Tp1, n>::operator[](int i) {
    if (i < 0 || i >= n) {
        std::cout << "Error, index out of bound." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}
template <class Tp1, int n>
Tp1  ArrayTp<Tp1, n>::operator[](int i) const {
    if (i < 0 || i >= n) {
        std::cout << "Error, index out of bound." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

#endif