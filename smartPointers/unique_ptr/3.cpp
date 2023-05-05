/*
auto_ptr指针不推荐使用(deprecated)
1. 指向同一地址的auto_ptr引发多次析构
2. 两个auto_ptr对象发生赋值操作时，右者对象会丧失该所有权
3 引用传递，不会产生临时变量
4. unique_ptr是右值，可以给share_ptr
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
    shared_ptr<int> sptr4 = ptr3;
    shared_ptr<int> sptr4 = unique_ptr<int>(new int(6)); // unique_ptr是右值，可以给share_ptr
    return 0;
}