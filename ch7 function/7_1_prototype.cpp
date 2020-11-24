#include <iostream>

/**
* 为什么要函数原型
* 1. 约定了函数参数格式，可以在编译期间检查格式，转换参数格式
* 2. 约定了返回值格式，编译器可以知道去读取几个字节
* 3. 没有原型而在文件中查找函数格式，效率不高
* 4. 有些函数在其他文件中，可能无权限去检索他们

* c++ 中原型必须提供，c中可选

**/

double simple(int x);

int main () {
    using namespace std;
    cout << "Give me a number";
    int a;
    cin >> a;
    double result = simple(a);
    cout << "Result is " << result << endl;
    return 0;
}

double simple(int x) {
    return x * x * x;
}