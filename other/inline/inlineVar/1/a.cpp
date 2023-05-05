#include <vector>
#include <iostream>
#include <utility>
using namespace std;

/* bar1.cc */
inline int Foo(int x) {
    static int factor = 1;
    return x * (factor++);
}
int Bar1() {
    return Foo(1);
}