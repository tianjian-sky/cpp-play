#include <iostream>


/**
* 语言的链接性：
* c，c++会为每个函数生成一个内部的独一无二的代号，而对于重载的函数会进行名称矫正。因此如果c，和c++都定义了一个同名函数，c++内有此函数的重载函数。
* 那么如果想要调用c中预编译的此函数很可能调用不到，因为c++使用自己的名称规则寻找此函数的内部名称。如果想要使用c的内部名称就可以这样
* extern "C" void spiff(int);
* extern void spiff (int); 默认是c++的命名规则。
* extern "C++" void spiff(int)
**/


static void Say(char *);
void SayAgain(char *ch);
int main () {
    using namespace std;
    return 0;
}

static void Say(char *ch) {
    using namespace std;
    cout << ch << endl;
}