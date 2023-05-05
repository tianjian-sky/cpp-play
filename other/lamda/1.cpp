#include <vector>
#include <iostream>
#include <utility>
using namespace std;

/*
* lamda
* 只有一条语句时可以自动类型推断返回值类型
* 否则需要使用返回类型后置语法
*/

/*
* 1. 让函数定义离使用的地方距离接近
* 2.lamda变量
* 3. Lambda 表达式访问外部变量
[ ] 表示不捕获任何变量
[=] 表示按值传递的方法捕获父作用域的所有变量
[&] 表示按引用传递的方法捕获父作用域的所有变量
[=, &a] 表示按值传递的方法捕获父作用域的所有变量，但按引用传递的方法捕获变量a
[&, a] 表示按引用传递的方法捕获父作用域的所有变量，但按值传递的方法捕获变量a
*/


int main () {
    int a = 1;
    int b = 2;
    int c = 3;
    auto lamda1 = [](int x)->int {
        // cout << a << ":" << b << endl;
        return  x + 1;
    };
    auto lamda12 = [&](int x)->void {
        cout << a << ":" << b << endl;
        a++;
        b++;
    };
    auto lamda3 = [&a, &b, c](int x)->void {
        cout << a << ":" << b  << ":" << c << endl;
        a++;
        b++;
        // c++;
    };
    cout << lamda1(3) << endl;
    lamda12(3);
    cout << a << ":" << b  << ":" << c << endl;
    lamda3(3);
    cout << a << ":" << b  << ":" << c << endl;
}
