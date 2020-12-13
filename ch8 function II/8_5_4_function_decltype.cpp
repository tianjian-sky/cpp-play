#include <iostream>

/**
* 1。decltype 关键字
* 针对c++的函数模板，多个类型参数的变量结合后，最后的计算值的类型只能在运行时确定，取决于他们的入参类型组合
* 如：
* T1 x, T2 y
* ?type? xpx = x + y
* xpx的类型可能是
* double(T1: int, T2 double)
* int(T1: short, T2 int)
*/

/**
*2. 后置返回类型
* 对于函数定义 的返回值，无法使用decltype，这时就可以用后置返回类型
*/


template<class T1, class T2>
void ft (T1 x, T2 y);

/**
*2. 后置返回类型
* 对于函数定义 的返回值，无法使用decltype，这时就可以用后置返回类型
*/

template<class T1, class T2>
auto ft2 (T1 x, T2 y) -> decltype(x+y);

int main () {
    using namespace std;

    short s = 1;
    int i = 2;
    float f = 123.2;
    double d = 3.3;
    long l = 4.4L;
    char c = 'a';

    char *add1, *add2, *add3;


    // 1. decltype 未用括号引起的标识符，类型与该标识符相同
    decltype (c) darktype = c;
    add1 = &c;
    add2 = &darktype;
    cout << "\n\ndarktype:" << typeid(darktype).name() << endl;
    cout << "address compare:" << add1 << "    " << add2 << endl;
    // 2. decltype 函数调用，与函数调用返回值类型相同

    // 3. decltype 一个左值，则未指向其类型的引用
    // 意味着必须加括号，以便于情况1相区别开.

    decltype((c)) lv_dark = c;
    add3 = &lv_dark;
    cout << "\n\nlv darktype:" << typeid(lv_dark).name() << endl;
    cout << "address compare:" << add1 << "    " << add3 << endl;

    // 其他情况，decltype 是表达式的类型
    ft(s, i);
    ft(i, d);
    ft(i, f);
    ft(d, l);
    ft(i, c);
    ft(i, l);

    auto unknow = ft2(i, f);
    cout << "\n\nTrailing return type" << unknow << "   " << &unknow << "   " << typeid(unknow).name() << endl;
    return 0; 
}


template<class T1, class T2>
void ft (T1 x, T2 y) {
    using namespace std;
    decltype(x+y) xpy = x + y;
    typedef decltype(x+y) my_dark_type; // 与typedef联用
    cout << typeid(xpy).name() << endl;
}

/**
*2. 后置返回类型
* 对于函数定义 的返回值，无法使用decltype，这时就可以用后置返回类型
*/

auto ft2 (T1 x, T2 y) -> decltype(x+y) {
    return x + y;
}