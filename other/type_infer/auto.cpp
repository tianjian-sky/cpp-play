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

/*

auto 的限制

前面介绍推导规则的时候我们说过，使用 auto 的时候必须对变量进行初始化，这是 auto 的限制之一。那么，除此以外，auto 还有哪些其它的限制呢？

1) auto 不能在函数的参数中使用。
这个应该很容易理解，我们在定义函数的时候只是对参数进行了声明，指明了参数的类型，但并没有给它赋值，只有在实际调用函数的时候才会给参数赋值；而 auto 要求必须对变量进行初始化，所以这是矛盾的。

2) auto 不能作用于类的非静态成员变量（也就是没有 static 关键字修饰的成员变量）中。

3) auto 关键字不能定义数组，比如下面的例子就是错误的：
char url[] = "http://c.biancheng.net/";
auto  str[] = url;  //arr 为数组，所以不能使用 auto

4) auto 不能作用于模板参数，请看下面的例子：


*/
void f(auto n) {}; // 此处不允许用auto

template <typename T>
class A{
    //TODO:
};


int main () {
    auto str[];
    A<auto>aa;
    auto n = 10;
    auto f = 12.8;
    auto p = &n;
    auto url = "http://c.biancheng.net/cplus/";

    int  x = 0;
    auto *p1 = &x;   //p1 为 int *，auto 推导为 int
    auto  p2 = &x;   //p2 为 int*，auto 推导为 int*
    auto &r1  = x;   //r1 为 int&，auto 推导为 int
    auto r2 = r1;    //r2 为  int，auto 推导为 int


}