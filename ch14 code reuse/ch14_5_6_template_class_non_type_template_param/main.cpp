#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"
using std::cin;
using std::cout;
using std::endl;


/*
* 模板的非类型参数:
* 可以是整型，枚举，引用，指针。
* 因此double 不可以，double*可以
* 不可以对模板类型变量进行++，&等操作
*
*/

/*
* 表达式参数方法使用的是内存栈，自动维护，不同于new，delete，因此速度更快
*/

/*
* 表达式参数方法的缺点是每种参数的数组大小都将生成自己的模板。
*/

int main () {
    ArrayTp<int, 5> arr(999);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << ";" << endl;
    }
    return 0;
}