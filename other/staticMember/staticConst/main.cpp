#include <vector>
#include <iostream>
#include "a.h"
using namespace std;


/*
1. 头文件被多个翻译单元的 include 的时候 静态变量只能初始化一次
*/
/*
2. 类的静态成员如果不在类外提供一个符号, 那么对 A::a 取地址的时候, 链接器会提示没有符号 (undefined reference to A::a ).
*/

/*
https://www.zhihu.com/question/410796312/answer/1370876431

那么，你就要了解下，const这个关键字，其实代表的不是常量，而是read-only，但static const代表的却是常量，和它对应的是宏和枚举，那么，和其他常量一样，static const在run-time是无法改变的。例如，你可以用const_cast给const数据暴力赋值。int* ptr = const_cast<int*>(&t.m);
*ptr = 5;
虽然不太优雅，但这是OK的，因为t.m在运行中是存储在栈区的，该段内存是动态的，虽然有只读属性，但在run-time的时候可以改。但这样，你就不行。int *ptr = const_cast<int*>(&(test::n));
*ptr = 8;
这不会报编译错误，但在运行的时候会报一个write access violation错误，因为test::n被存储到了全局数据区，该段内存是静态的，在编译期就已经分配好，在run-time的时候无法改变。因此，这就是这二者在类中的区别，const 是read-only，而const static int是constant

*/

/*
1.const_cast 只能转换指针
2. 编译器优化，对const指针转换并修改值时，指针指向地址相同，但是输出结果不同
3.不能使用 const_cast 运算符直接重写常量变量的常量状态
*/
extern int global;

int main () {
    cout << "golbal:" << global << endl;
    A a;
    a.print1();
    a.print2();
    cout << A::a << endl;
    B b;
    b.print1();
    b.print2();
    cout << B::aaa << endl;
    cout << &(B::aaa) << endl; // symbol(s) not found for architecture arm64
}