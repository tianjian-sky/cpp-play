#include <iostream>
#include <string>
using namespace std;


/**
 * 没有办法通过args[2]这样的下标形式访问参数包中参数
*/
void fun() {
    cout << "用于参数展开结束调用" << endl;
}

template<class T, class... Args>
void fun (T value, Args &... args) {
    cout << value << endl;
    fun(args...);
}

int main() {
    int n = 15;
    double d  = 3.14;
    char ch = 'a';
    string str = "hello";
    fun(n, d, ch, str);
}