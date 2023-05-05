#include <iostream>
using namespace std;


/**
 * 关键字 constexpr 是在 C++11 中引入的，并在 C++14 中进行了改进。 它表示 constant（常数）表达式。 
 *  与 const 一样，它可以应用于变量：如果任何代码试图 modify（修改）该值，将引发编译器错误。 
 *  与 const 不同，constexpr 也可以应用于函数和类 constructor（构造函数）。 constexpr 指示值或返回值是 constant（常数），如果可能，将在编译时进行计算
 * 
*/

/**
 * const 与 constexpr 变量之间的主要 difference（区别）是，const 变量的初始化可以推迟到运行时进行。 constexpr 变量必须在编译时进行初始化。 所有的 constexpr 变量都是 const。
*/

/**
 * constexpr 变量
const 与 constexpr 变量之间的主要 difference（区别）是，const 变量的初始化可以推迟到运行时进行。 constexpr 变量必须在编译时进行初始化。 所有的 constexpr 变量都是 const。

如果一个变量具有文本类型并且已初始化，则可以使用 constexpr 声明该变量。 如果初始化是由 constructor（构造函数）performed（执行）的，则必须将 constructor（构造函数）声明为 constexpr。

当满足以下两个条件时，引用可以被声明为 constexpr：引用的对象是由 constant（常数）常数表达式初始化的，初始化期间调用的任何隐式转换也是 constant（常数）表达式。

constexpr 变量或函数的所有声明都必须具有 constexpr specifier（说明符）。
*/

/**
 * constexpr 函数
constexpr 函数是在使用需要它的代码时，可在编译时计算其返回值的函数。 使用代码需要编译时的返回值来初始化 constexpr 变量，或者用于提供非类型模板自变量。 当其自变量为 constexpr 值时，函数 constexpr 将生成编译时 constant（常数）。 使用非 constexpr 自变量调用时，或者编译时不需要其值时，它将与正则函数一样，在运行时生成一个值。 （此双重行为使你无需编写同一函数的 constexpr 和非 constexpr 版本。）

constexpr 函数或 constructor（构造函数）通过隐式方式 inline。
 * 
 constexpr 函数必须只接受并返回文本类型。

constexpr 函数可以是递归的。

为forc++20， constexpr 函数不能为 虚拟函数，当 const封闭类具有任何虚拟基类时，不能将 ructor 定义为 constexpr 。 在 C++20 及更高版本中， constexpr 函数可以是虚拟函数。 Visual Studio 2019 版本 16.10 及更高版本在指定if/std:c++20或更高版本编译器选项时支持constexpr虚拟函数。

主体可以定义为 = default 或 = delete。

正文不能包含如何 goto 语句或 try 块。

可以将非 constexpr 模板的显式专用化声明为 constexpr：

constexpr 模板的显式专用化不需要同时也是 constexpr：
*/
/**
 * 下规则适用于 Visual Studio 2017 及更高版本中的 constexpr 函数：

它可以包含 if 和 switch 语句，以及所有循环语句，包括 for、基于范围的 for、while、和 do-while。

它可能包含局部变量声明，但必须初始化该变量。 它必须是文本类型，不能是 static 或线程本地的。 本地声明的变量不需要是 const，并且可以变化。

constexpr 非 static 成员函数不需要通过隐式方式 const。
*/


constexpr float exp(float x, int n)
{
    cout << "constexp fun running!" << endl;;
    return n == 0 ? 1 :
        n % 2 == 0 ? exp(x * x, n / 2) :
        exp(x * x, (n - 1) / 2) * x;
}

int main() {
    cout << exp(1.1, 3) << endl; //error constexpr function never produces a constant expression
    cout << exp(2.1, 3)<< endl;
}