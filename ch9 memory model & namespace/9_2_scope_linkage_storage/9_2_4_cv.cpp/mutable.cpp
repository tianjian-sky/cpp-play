#include <iostream>
const int Ar_size = 10;

/**
 * mutable的作用有两点：
    （1）保持常量对象中大部分数据成员仍然是“只读”的情况下，实现对个别数据成员的修改；
    （2）使类的const函数可以修改对象的mutable数据成员。

 * 使用mutable的注意事项：
    （1）mutable只能作用于类的非静态和非常量数据成员。
    （2）在一个类中，应尽量或者不用mutable，大量使用mutable表示程序设计存在缺陷。
*/

struct data {
    char name[30];
    mutable int accesses;
    // int accesses; // veep.accesses += 1;  // error:assignment of member 'data::accesses' in read-only object
};


int main () {
    const data veep = {"hello world", 0};
    veep.accesses += 1; 
    
    return 0;
}

