#include <iostream>
#include <cstdlib>

/*
异常处理
1. std::abort() 位于cstdlib
2. try-catch
3. noexcept 关键词
    告诉编译器，函数中不会发生异常，有利于编译器优化代码。若发生了异常，会调用std::terminate()
4. noexcept(常量表达式) 如果表达式不发生异常，则函数一定不发生异常
    * noexcept不会对表达式求值
*/

/*
以下情况鼓励使用noexcept
    移动构造
    移动赋值
    析构函数 默认noexcept
*/

/*
函数上的 noexcept 说明不是一种编译时检查；它只不过是程序员告知编译器函数是否可以抛出异常的一种方法。编译器能用此信息启用不会抛出的函数上的某些优化，
以及启用能在编译时检查特定表达式是否声明为可抛出任何异常的 noexcept 运算符。
例如，诸如 std::vector 的容器会在元素的移动构造函数是 noexcept 的情况下移动元素，否则就复制元素（除非复制构造函数不可访问，但有可能会抛出的移动构造函数只会在放弃强异常保证的情况下考虑）。

*/
using namespace std;
class MyException {
    public:
        MyException (const char * s): msg(s) {}
        const char* msg;
};

template <class T>
class Addable {
    public:
        T op;
        Addable(T any):op(any) {};
        T add(Addable<T> another) noexcept(true) {
            return op + another.op;
        }
};

template <class T>
T add (T a, T b) noexcept(false) {
    return a + b;
}

float _devide(int a, int b) {
    if (b == 0) {
        throw "devide 0";
    } else {
        return a / b;
    }
}
float divide(int a, int b) noexcept(false) {
        // char * msg = "devide zero error"; // 这在C++11标准中是错误的，会认为“xiao ming”是字符常量，定义一个指针去指向它，这样是有问题的，正确的定义方式是：
       return _devide(a, b);
}

template <class T>
T add2 (Addable<T> c, Addable<T> d) noexcept(noexcept(c.add(d)))  {
    std::cout << "---add2" << std:: endl;
    // std::string abc= "xyz";
    // std::cout << noexcept(c.add(d)) << std:: endl;
    return c.add(d);
}

int main() {
    std::cout << noexcept(add<string>("a", "b")) << std:: endl; // noexcept不会对表达式求值
    std::cout << noexcept(add<int>(1, 2)) << std:: endl; // noexcept不会对表达式求值
    Addable<int> a = Addable<int>(1);
    Addable<int> b = Addable<int>(2);
    add2(a, b);
    std::cout << noexcept(add2(a, b)) << std::endl;
}