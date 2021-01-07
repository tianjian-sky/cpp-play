#include <iostream>


/**
* 函数的链接性：
* c++不允许在一个函数中定义另外一个函数，因此所有函数的持续性都是静态的。
* 默认情况下，函数的链接性是外部的，所以在一个文件中定义的函数，可以在另外一个文件中使用（但是必须包含其原型）。extern关键字也是可选的。
* 也可以在函数定义前加static，使其成为内部链接性
**/

static void Say(char *); //  undefined reference to `Say(char*)'

void SayAgain(char *ch) {
    Say(ch);
}
