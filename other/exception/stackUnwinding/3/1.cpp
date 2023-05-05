#include <iostream>
#include <memory>
#include <cmath>
#include <string>
#include "a.h"

using namespace std;
/*
    栈展开
        函数出现异常，程序释放栈（当前函数内存和局部对象），直到第一个try块的返回地址，然后控制权转到try块后的异常处理，而不是返回地址后的第一条语句。

    对new 动态分配的内存，栈展开期间不会释放资源。
    析构函数从不应该抛出异常
    构造期间剖出异常，此时对象可能只是部分被构造，需要保证能撤销这些已构造成员
    未捕获的异常会终止程序

    智能指针能在栈栈开时释放

*/
void afun();
void bfun();
void cfun();

void afun () {
    auto_ptr<A> a1 (new A("a_auto"));
    unique_ptr<A> a2 (new A("a_unique"));
    shared_ptr<A> a3(new A("a_share"));
    cout << a3.use_count() << endl;
    bfun();
}
void bfun () {
    A a2 = A("a2");
    cfun();
}
void cfun () {
    new A("a_new");
    throw Ex("1");
}

int main () {
    try {
        afun();
    } catch(Ex & e) {
        cout << e.msg << endl;
        cout << "end e";
    }
    cout << "end";
}
