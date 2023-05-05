/*
auto_ptr指针不推荐使用(deprecated)
1. 指向同一地址的auto_ptr引发多次析构
2. 两个auto_ptr对象发生赋值操作时，右者对象会丧失该所有权
*/
#include "iostream"
#include "memory"
#include "exception"
using namespace std;

int main () {
    int *p = new int(3);
    unique_ptr<int> uptr1(p);
    unique_ptr<int> uptr2;
    uptr2 = uptr1; // cannot be assigned because its copy assignment operator is implicitly deleted

    // 临时的unique_ptr指针可以转移所有权
    unique_ptr<int> ptr3 = unique_ptr<int>(new int(5)); // allowed
    return 0;
}