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

/*
    C++17之后，类的静态成员变量在类内通过static声明，在类外（但是在头文件中）初始化不加inline的话可能会导致重定义从而出现链接错误，而加了inline 就不会出错，类似有无inline修饰的全局函数；
    C++ 17之前必须在.cpp中初始化静态成员才不会出现重定义的错误，在.h中初始化还是会导致重定义错误，因为C++17之前的标准不支持inline修饰类的静态成员变量；
*/

/*

C++ 17之前为什么类的非const静态成员必须类外初始化？

因为类的静态成员是类所有，不属于任何对象，如果放在类内初始化，那么每个对象构造的时候都会对该静态成员进行初始化，这样会导致其他对象在使用该静态成员时出现意想不到的错误，所以禁止类内初始化非const静态变量；

而const修饰的静态成员变量是在类中初始化，对象构造的时候不会再进行初始化操作，对象构造的时候默认该变量已经初始化了，反正也不能修改它；

C++17之前的类内静态变量必须在类外初始化，如果有头文件和实现文件，最好在类的实现文件中对静态变量做初始化，如果在头文件中做初始化，也会引起重定义的问题；

C++17 之后可以在类内通过static inline 直接进行声明与初始化，也可以在类内部进行声明，在类外（但是在头文件中）通过inline 进行初始化。其实就是新标准通过inline能够保证类内静态变量只初始化一次，全局共享一份数据，而之前的标准是不允许inline修饰类的静态成员变量的；
*/

/*
inline on variables only has effect when you define the same variable in several translation units. Since static restricts the variable to a single TU, you can't have more than one definition.

At class scope:

inline can only appear on static variables.

It has its normal effect, allowing you to initialize the variable directly in the header. Either:
*/
extern int global;
int main () {
    // int b;
    // int b;
    cout << "golbal:" << global << endl;
    A a;
    a.print1();
    a.print2();
    cout << A::a << endl;
    cout << &(A::a) << endl; // symbol(s) not found for architecture arm64
    cout << "try modify const" << endl;
    const int c1 = 3;
    int* c2 = const_cast<int*> (&c1);
    *c2 = 88;
    /*
    * 编译器优化，c2与&c1指向地址相同，但是*c2 与 c1 值显示不同
    * 编译时常量替换
    */
    cout << &c1 << ":" << c2 << endl;
    cout << *c2 << ":" << c1  << endl;
    cout << "try modify static const" << endl;
    cout << &(A::a) << endl; // bus error
    int* sc = const_cast<int*> (&(A::a));
    *sc = 9;
}