/*
 模版变量
 需要c++17

*/



//简化的例子和非类型参数
#include <iostream>
#include <array>

template<int N>
std::array<int, N> arr{}; // 定义数组并初始化

template<auto N>
constexpr decltype(N) dval = N;  

void TestArray()
{
    std::cout << dval<'c'> << std::endl;  

    std::cout << dval<33> << std::endl;  


    arr<10>[0] = 42; // 设置全局arr第1个元素的值
    for (std::size_t i = 0; i < arr<10>.size(); ++i) 
    { // 使用arr中的值
        std::cout << arr<10>[i] << std::endl;
    }

    arr<5>[0] = 42; // 设置全局arr第1个元素的值
    for (std::size_t i = 0; i < arr<5>.size(); ++i) 
    { // 使用arr中的值
        std::cout << arr<5>[i] << std::endl;
    }
}
namespace  mystd {
    template<typename T>
    class numeric_limits 
    {
    public:

        static constexpr bool is_signed = false;

    };
}
//可以定义：
template<typename T>
constexpr bool isSigned = mystd::numeric_limits<T>::is_signed;
void TestSimple() 
{
    bool sig = isSigned<char>;
    std::cout << "mystd numeric_limits is:" << sig << std::endl;
}
int main()
{
    TestArray();
    TestSimple();
   
    return 0;
}