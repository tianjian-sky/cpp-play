#include <vector>
#include <iostream>
#include <utility>
using namespace std;

/**
 * Definitions and ODR (One Definition Rule)
 * https://link.zhihu.com/?target=https%3A//en.cppreference.com/w/cpp/language/definition
 * 
*/

/**
 * inline函数
 * 
 * 若一个非static函数在多个编译单元中被重复定义，那么在链接阶段会发生multiple definition的错误，这是因为面对同一符号的多个定义，链接器并不知道使用哪个。但是对于header-only的程序库来说，所有的函数定义都位于头文件，若不加特殊处理被多个源文件包含，则一定会发生multiple definition的错误。解决这个问题的方法是在函数声明处加上inline修饰，这样的话编译器在处理该函数时就会认为它是一个弱符号，链接器在面对多个名字相同的弱符号时只会保留其中一个的定义（具体的保留规则视编译器而定）

    作者：吼姆桑
    链接：https://www.zhihu.com/question/24185638/answer/2404153835
    来源：知乎
 * 
*/
/* main.cc */
int Bar1(),Bar2();
int main() {
    return Bar1() + Bar2();
}