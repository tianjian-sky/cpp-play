/*
template <typename T>
T minimum(const T& lhs, const T& rhs)
{
    return lhs < rhs ? lhs : rhs;
}

*/

/*

在c++98添加关键词typename之前，c++使用class关键词创建模版
template <class T, class U, class V> class Foo{};

*/

/*
非类型参数
与其他语言（如 C# 和 Java）中的泛型类型不同，C++ 模板支持非类型参数，也称为值参数。

template<typename T, size_t L>
class MyArray
{
    T arr[L];
public:
    MyArray() { ... }
};

MyArray<MyClass*, 10> arr;

*/

/*
非类型模板参数的类型推导
在 Visual Studio 2017 及更高版本中，在 /std:c++17 模式或更高版本中，编译器会推导使用 auto 声明的非类型模板参数的类型：
*/

#include "iostream"
template <auto x> constexpr auto constant = x;
int main () {
    auto v1 = constant<5>;      // v1 == 5, decltype(v1) is int
    auto v2 = constant<true>;   // v2 == true, decltype(v2) is bool
    auto v3 = constant<'a'>;    // v3 == 'a', decltype(v3) is char
}