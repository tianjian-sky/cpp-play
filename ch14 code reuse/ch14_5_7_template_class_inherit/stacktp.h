#ifndef STACKTP_H_
#define STACKTP_H_

template <class Tp1>
class Array {
    private:
        Tp1 entry;
};

template <class Tp0>
class GrowArray: public Array<Tp0> {

};

template <class T>
class Stack {
    public:
        Array <T> ar;
};

#endif