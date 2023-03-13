/*
关键字 constexpr 是在 C++11 中引入的，并在 C++14 中进行了改进。 它表示 constant（常数）表达式。 与 const 一样，它可以应用于变量：如果任何代码试图 modify（修改）该值，将引发编译器错误。 与 const 不同，constexpr 也可以应用于函数和类 constructor（构造函数）。 constexpr 指示值或返回值是 constant（常数），如果可能，将在编译时进行计算。

每当需要 const 整数时（如在模板自变量和数组声明中），都可以使用 constexpr 整数值。 如果在编译时（而非运行时）计算某个值，它可以使程序运行速度更快、占用内存更少。

为了限制计算编译时 constant（常数）的复杂性及其对编译时间的潜在影响，C++14 标准要求 constant（常数）表达式中所涉及的类型为文本类型。

*/

/*
const 与 constexpr 变量之间的主要 difference（区别）是，const 变量的初始化可以推迟到运行时进行。 constexpr 变量必须在编译时进行初始化。 所有的 constexpr 变量都是 const。
*/

/**
 * 
 * constexpr 函数
constexpr 函数是在使用需要它的代码时，可在编译时计算其返回值的函数。 使用代码需要编译时的返回值来初始化 constexpr 变量，或者用于提供非类型模板自变量。 当其自变量为 constexpr 值时，函数 constexpr 将生成编译时 constant（常数）。 使用非 constexpr 自变量调用时，或者编译时不需要其值时，它将与正则函数一样，在运行时生成一个值。 （此双重行为使你无需编写同一函数的 constexpr 和非 constexpr 版本。）
 * 
*/

