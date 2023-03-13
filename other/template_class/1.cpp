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