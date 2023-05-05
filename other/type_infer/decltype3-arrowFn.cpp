/*
decltype 是 C++11 新增的一个关键字，它和 auto 的功能一样，都用来在编译时期进行自动类型推导。不了解 auto 用法的读者请转到《C++ auto》。

既然已经有了 auto 关键字，为什么还需要 decltype 关键字呢？因为 auto 并不适用于所有的自动类型推导场景，在某些特殊情况下 auto 用起来非常不方便，甚至压根无法使用，所以 decltype 关键字也被引入到 C++11 中。

auto 和 decltype 关键字都可以自动推导出变量的类型，但它们的用法是有区别的：

auto 根据=右边的初始值 value 推导出变量的类型，而 decltype 根据 exp 表达式推导出变量的类型，跟=右边的 value 没有关系。

*/

/*
decltype 可以写成下面的形式：
decltype(exp) varname;

exp 注意事项
原则上讲，exp 就是一个普通的表达式，它可以是任意复杂的形式，但是我们必须要保证 exp 的结果是有类型的，不能是 void；例如，当 exp 调用一个返回值类型为 void 的函数时，exp 的结果也是 void 类型，此时就会导致编译错误。

*/

/*
如果 exp 是一个不被括号( )包围的表达式，或者是一个类成员访问表达式，或者是一个单独的变量，那么 decltype(exp) 的类型就和 exp 一致，这是最普遍最常见的情况。
如果 exp 是函数调用，那么 decltype(exp) 的类型就和函数返回值的类型一致。
如果 exp 是一个左值，或者被括号( )包围，那么 decltype(exp) 的类型就是 exp 的引用；假设 exp 的类型为 T，那么 decltype(exp) 的类型就是 T&。
*/

/*
箭头函数使用decltype返回后置类型，其使用在函数的返回类型需要通过模板参数进行推导，使用在decltype()和declval()不方便的场景

*/
#include <iostream>
#include <string>
using namespace std;

class Base{
public:
    int x;
    int operator * (int b) {
        return x * b;
    }
};

using namespace std;

//函数声明
int& func_int_r(int, char);  //返回值为 int&
int&& func_int_rr(void);  //返回值为 int&&
int func_int(double);  //返回值为 int
const int& fun_cint_r(int, int, int);  //返回值为 const int&
const int&& func_cint_rr(void);  //返回值为 const int&&

// 不使用箭头函数，使用decltype + declval的组合，但较为繁琐
decltype(declval<Base>() * declval<int>()) arrowFn0 (Base b, int a);

auto arrowFn (Base b, int a) -> decltype(b*a);

//decltype类型推导
int main () {
    int n = 100;
    decltype(func_int_r(100, 'A')) a = n;  //a 的类型为 int&
    decltype(func_int_rr()) b = 0;  //b 的类型为 int&&
    decltype(func_int(10.5)) c = 0;   //c 的类型为 int
    decltype(fun_cint_r(1,2,3))  x = n;    //x 的类型为 const int &
    decltype(func_cint_rr()) y = 0;  // y 的类型为 const int&&

    const Base obj{10};
    //带有括号的表达式
    decltype(obj.x) aaa = 0;  //obj.x 为类的成员访问表达式，符合推导规则一，a 的类型为 int
    decltype((obj.x)) bb = aaa;  //obj.x 带有括号，符合推导规则三，b 的类型为 int&。
    //加法表达式
    int nn = 0, m = 0;
    decltype(nn + m) ccc = 0;  //n+m 得到一个右值，符合推导规则一，所以推导结果为 int
    decltype(n = nn + m) d = ccc;  //n=n+m 得到一个左值，符号推导规则三，所以推导结果为 int&

    cout << arrowFn0(obj, n) << endl;
    cout << arrowFn(obj, n) << endl;

}

decltype(declval<Base>() * declval<int>()) arrowFn0 (Base b, int a) {
    return b.x * a;
}
auto arrowFn (Base b, int a) -> decltype(b*a) {
    return b.x * a;
}
