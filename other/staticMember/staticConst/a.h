
#include <iostream>
#include <utility>
using namespace std;
// #ifndef STRINGBAD_H_ 防止同一个声明多次插入到单个文件中
#define STRINGBAD_H_

class A {
    public:
        static const int a = 9999; // 不生成符号
    A () {};
    void print1 ();
    void print2 ();
};

class B {
    public:
        static inline constexpr int aaa = 9999; // inline 变量 生成符号 c++17 0x100707e24
    B () {};
    void print1 ();
    void print2 ();
};

// #endif