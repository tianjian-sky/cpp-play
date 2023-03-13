/*
在之前的 C++ 版本中，auto 关键字用来指明变量的存储类型，它和 static 关键字是相对的。auto 表示变量是自动存储的，这也是编译器的默认规则，所以写不写都一样，一般我们也不写，这使得 auto 关键字的存在变得非常鸡肋。

C++11 赋予 auto 关键字新的含义，使用它来做自动类型推导。也就是说，使用了 auto 关键字以后，编译器会在编译期间自动推导出变量的类型，这样我们就不用手动指明变量的数据类型了。

*/

/*
auto 除了可以独立使用，还可以和某些具体类型混合使用，这样 auto 表示的就是“半个”类型，而不是完整的类型。请看下面的代码：
*/

/*
使用 auto 将删除引用、 const 限定符和 volatile 限定符。 请考虑以下示例：
*/
#include "iostream"
using namespace std;

int main () {
    int count = 10;
    int& countRef = count;
    auto myAuto = countRef; // 使用 auto 将删除引用、 const 限定符和 volatile 限定符。 请考虑以下示例：
    cout << "-----" << endl;
    countRef = 11;
    cout << count << " ";
    myAuto = 12;
    cout << count << endl;
    cout << "-----" << endl;

    int  x = 0;
    const auto n = x;  //n 为 const int ，auto 被推导为 int
    auto f = n;      //f 为 const int，auto 被推导为 int（const 属性被抛弃）
    // cout << n++ << endl; // cannot assign to variable 'n' with const-qualified type 'const int'
    cout << f++ << endl;
    const auto &r1 = x;  //r1 为 const int& 类型，auto 被推导为 int
    auto &r2 = r1;  //r1 为 const int& 类型，auto 被推导为 const int 类型
    r2++;


}