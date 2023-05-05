/*
auto_ptr指针不推荐使用(deprecated)
1. 指向同一地址的auto_ptr引发多次析构
2. 两个auto_ptr对象发生赋值操作时，右者对象会丧失该所有权
3 引用传递，不会产生临时变量
*/
#include "iostream"
#include "memory"
#include "vector"
#include "exception"
using namespace std;

void show1 (unique_ptr<int> pt) {
    cout << *pt << endl;
}

void show2 (unique_ptr<int> & pt) { // 引用传递，不会产生临时变量
    cout << *pt << endl;
}

int main () {
    vector<unique_ptr<int>> vp;
    for (int i = 0; i < 10; i++) {
        vp.emplace_back(unique_ptr<int>(new int(i))); // 临时右值可以转移所有权
    }
    show1(vp[3]); //  call to implicitly-deleted copy constructor of 'unique_ptr<int>'
    show2(vp[3]); // 引用传递，不会产生临时变量
    return 0;
}