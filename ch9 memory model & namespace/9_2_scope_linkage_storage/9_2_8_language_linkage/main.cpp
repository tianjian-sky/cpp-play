#include <iostream>


/**
* 函数的链接性：
* c++不允许在一个函数中定义另外一个函数，一次所有函数的持续性都是静态的。
* 默认情况下，函数的链接性是外部的，所以在一个文件中定义的函数，可以在另外一个文件中使用（但是必须包含其原型）。extern关键字也是可选的。
* 也可以在函数定义前加static，使其成为内部链接性
**/

/**
 * 除非函数是静态的，否则编译器将在所有文件中找此函数的定义。如果找到2个定义，则发出错误消息。如果在程序文件中没找到，就继续在库中搜索。
 * 可以定义与库函数同名的函数
**/

static void Say(char *);
void SayAgain(char *ch);
int main () {
    using namespace std;

    char charr[10] = "Hello!";
    Say(charr);
    SayAgain(charr);
    return 0;
}

static void Say(char *ch) {
    using namespace std;
    cout << ch << endl;
}