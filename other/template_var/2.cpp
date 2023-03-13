/*
 模版变量
 需要c++17

*/



//简化的例子和非类型参数
#include <iostream>
#include <array>

//返回值例子
template<typename T>
constexpr T PI = T(3.1415926535897932385);

template<typename T=long double>
T VAL = T(3.1415926535897932385);

template<typename T>
T circular_area(T r)
{
    return PI<T>*r*r;
}

int main()
{
    VAL<float> = 3.1415;
    std::cout << VAL<float> << std::endl;
    std::cout << VAL<> << std::endl;
    std::cout << PI<int> << std::endl;
    std::cout << PI<double> << std::endl;
    std::cout << circular_area(2.0) << std::endl;   
    return 0;
}
