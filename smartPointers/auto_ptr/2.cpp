/*
auto_ptr指针不推荐使用(deprecated)
1. 指向同一地址的auto_ptr引发多次析构
2. 两个auto_ptr对象发生赋值操作时，右者对象会丧失该所有权
*/
#include "iostream"
#include "memory"
using namespace std;

int main () {
    int *p = new int(3);
    int *p2 = new int(5);
    {
        auto_ptr<int> aptr1(p);
        auto_ptr<int> aptr2(p2);
        aptr2 = aptr1;
        cout << p2 << ":" << p << endl;
        cout << *aptr2 << endl;
        cout << *aptr1 << endl; // freed
    }
    return 0;
}