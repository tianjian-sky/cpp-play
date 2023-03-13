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

/*
模板作为模板参数
模板可以是模板参数。 在此示例中，MyClass2 有两个模板参数：类型名称参数 T 和模板参数 Arr：
*/
#include "iostream"

template<typename T, template<typename T, int> class Arr>
class MyClass2
{
    T t; //OK
    Arr<T, 10> a;
};


int main () {
    


}