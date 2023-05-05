#include <vector>
#include <iostream>
#include <utility>
using namespace std;


/* bar2.cc */
inline int Foo(int x) {
    static int factor = 2;
    return x * (factor++);
}
int Bar2() {
    return Foo(2);
}