/*
auto_ptr指针不推荐使用(deprecated)
1. 指向同一地址的auto_ptr引发多次析构
2. 两个auto_ptr对象发生赋值操作时，右者对象会丧失该所有权
*/
#include "memory"
using namespace std;

int main () {
    int *p = new int(3);
    {
        auto_ptr<int> aptr1(p);
        auto_ptr<int> aptr2(p); // error for object 0x130606970: pointer being freed was not allocated
    }
    return 0;
}