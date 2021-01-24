#include <iostream>
#include "stringnew.h"

const int ArSize = 10;
const int MaxLen = 81;

const int & ConstRefReturn (const int & it) {
    return it;
}


int main () {
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "test const ref return" << endl;
    int a = 999;
    /*
    * 常量引用形式参数可以接收非常量引用实际参数
    * 实际参数出了函数也可修改，函数内不可修改
    */
    const int & b = ConstRefReturn(a);
    a +=1;
    cout << "a:"<< a << std::endl;
    return 0;
};


