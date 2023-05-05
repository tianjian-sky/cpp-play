#include <vector>
#include <iostream>
#include <utility>
#include <functional>
using namespace std;

/**
 * C++ static 关键词有三种完全不同的用途.

    表示一个静态储存期的变量, 且具有 internal linkage. (俗称 static 变量)
         通常它们在 main 函数开始之前初始化, 存活到 main 函数结束.
         static int a; // static 变量
    表示一个静态储存期的变量, 但是只在一个局部作用域可见, 保证仅初始化一次. (俗称 static local 变量)
        在一个函数体 (严格地说是 block scope) 内部, 用 static 变量就是 static local 变量. 比如
        void func() {
            static int a; // static local 变量
        }
        这类变量一般在第一次运行到这段代码的时候进行初始化. (付出的代价就是每次运行到这就要检查一下有没有初始化.)

        并且这个初始化是多线程安全的 (从 C++11), 可以用来做线程安全的单例 (常称为 Meyers 单例模型). 参考我写的这篇文章
    表示一个 class 的静态成员, 整个 class 共享一份, 不绑定到任何 instance. (俗称 static member 变量)
        class A {
            static int a;
        }
        很明显, 这个 a 地位类似于全局变量, 总不能每个翻译单元都生成一个符号吧?
        C++ 的设计者想出了方案, 再加一条语句用来专门用来生成符号, 顺便可以初始化. 就像这样

        // A.h (可以被多次包含)
        class A {
            static int a; // 不生成符号
        }

        // A.cpp (只翻译一次)
        #include "A.h"
        int A::a; // 生成一个符号

        那没有符号可以吗? 没有符号的东西没法放进内存, 所以也没法取地址, 没有办法 ODR-used.

        但, 我们这个例子中, 如果只是为了读取 A::a 的值, 那完全可以不把 A::a 放进内存, 那就不需要这个符号了. 而某些情况下确实不需要放进内存.

        C++ 为我们提供了这样的语法:
        // A.h
        class A {
            static const int a = 0;
            // 不生成符号
            // 但是可以编译时读 a 的值
        }
        所以按 C++ 的设计, 只有 const 的 static member 变量支持类内初始化. 如果不在类外提供一个符号, 那么对 A::a 取地址的时候, 链接器会提示没有符号 (undefined reference to A::a )

        line 的 static member 变量
        C++17 引入了 inline 的 static member 变量. 上面说总不能每个翻译单元都有一个符号吧, 但到了 C++17 以后答案是: 可以的. 加了 inline 以后就可以每个翻译单元生成一个符号, 然后链接器典型实现是选其中一个.
        // A.h (可以被多次包含)
        class A {
            static inline int a;
            // 生成符号, 可以取地址
            // 并且支持类内初始化!
        }
        C++17 之后, constexpr 的 static member 变量默认 inline , 所以你可以写出这样的代码:
        // A.h (可以被多次包含)
        class A {
            static constexpr int a = 0;
            // 生成符号, 可以取地址
            // 并且支持类内初始化!
        }
        知道了这些以后, 可能用 C++17 引入 inline variable 是最优雅的解决方案.
        顺便说一下, 新版 GCC 和 Clang 在 C++11/14 也能用 inline 变量, 所以 C++11/14 的时候 constexpr 也能推出 inline . 但是 MSVC 用不了.


*/

/*
模版实例化观察
*/

template <class T, class F>
T use(T t, F f) {
    static int count = 0; // 函数模版每次实例华，static都会新建，地址都不同
    count++;
    cout << "count:" << &count << ":" << count << endl;
    return f(t);
}

class A {
    private:
        double z;
    public:
        A(double z) : z(z) {}
        double operator ()(double p) {return z * p;};
};

class B {
    private:
        double z;
    public:
        B(double z) : z(z) {}
        double operator ()(double p) {return z + p;};
};

double square (double x) {
    return x * x;
}

double dub (double x) {
    return 2 * x;
}

/*
    上面的use的第二个参数，可以是函数指针，函数对象（仿函数），lamda，但是他们都有一个共性，接受一个double并且返回double，即他们的函数签名相同
    利用这点可以创建一个包装器
*/
function <double(double)> ef1 = dub; 
function <double(double)> ef2 = square;
function <double(double)> ef3 = A(3);
function <double(double)> ef4 = B(3);
function <double(double)> ef5 = [](double x)->double {return x * x;};
function <double(double)> ef6 = [](double x)->double {return x + x / 2.0;};

/**
 * 优化：
 * 包装器作为函数参数
*/


template <class T>
T use2(T t, function<T(T)> f) {
    static int count = 0; // 函数模版每次实例华，static都会新建，地址都不同
    count++;
    cout << "count:" << &count << ":" << count << endl;
    return f(t);
}

int main () {
    double a = 1.00;
    cout << "   " << use(a, dub) << endl;
    cout << "   " << use(a, square) << endl;
    cout << "   " << use(a, A(3)) << endl;
    cout << "   " << use(a, B(3)) << endl;
    cout << "   " << use(a, [](double x)->double {return x * x;}) << endl;
    cout << "   " << use(a, [](double x)->double {return x + x / 2.0;}) << endl;
    cout << "   ---     " << "使用包装器" << endl;
    /*
        上面的use的第二个参数，可以是函数指针，函数对象（仿函数），lamda，但是他们都有一个共性，接受一个double并且返回double，即他们的函数签名相同
        利用这点可以创建一个包装器
    */
    cout << "   " << use(a, ef1) << endl;
    cout << "   " << use(a, ef2) << endl;
    cout << "   " << use(a, ef3) << endl;
    cout << "   " << use(a, ef4) << endl;
    cout << "   " << use(a, ef5) << endl;
    cout << "   " << use(a, ef6) << endl;
    cout << "   ---     " << "使用包装器作为函数参数" << endl;
    cout << "   " << use2<double>(a, dub) << endl;
    cout << "   " << use2<double>(a, square) << endl;
    cout << "   " << use2<double>(a, A(3)) << endl;
    cout << "   " << use2<double>(a, B(3)) << endl;
    cout << "   " << use2<double>(a, [](double x)->double {return x * x;}) << endl;
    cout << "   " << use2<double>(a, [](double x)->double {return x + x / 2.0;}) << endl;
}
