
#include <iostream>
#include <utility>
using namespace std;
// #ifndef STRINGBAD_H_ 防止同一个声明多次插入到单个文件中
#define STRINGBAD_H_

class A {
    public:
        static inline const int a = 9999;
    A () {};
    void print1 ();
    void print2 ();
};

// #endif