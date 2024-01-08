

/**
 * C / C++ 可变参数的宏，__VA_ARGS__
 * 
 * https://www.jianshu.com/p/958162214e91
 * 
*/

/**
 * 1. 单独的 ... 和 __VA_ARGS__
    标准 C / C++ 语言宏定义的参数允许用三个小数点 ... 表示这里是可变参数，在宏替换的时候，用 __VA_ARGS__ 表示 ... 位置的所有的参数。
    例如：
    #define test1(...) printf(__VA_ARGS__)
    #define test2(fmt, ...) printf(fmt, __VA_ARGS__)

*/

/**
 * ##__VA_ARGS__
 * 当可变参数为0时，可以把前面,去掉，否则报错
*/


#include <iostream>

using namespace std;

#define MY_MACRO(x) (__extension__((x) * 2))
#define LOG(fmt, ...) printf("<%s:%d>:----" fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)


template<typename>
struct __em_asm_sig_builder {};

template<typename... Args>
struct __em_asm_type_tuple {};

// Instead of std::make_tuple
template<typename... Args>
__em_asm_type_tuple<Args...> __em_asm_make_type_tuple(Args... args) {
    return {};
}

#define _EM_ASM_PREP_ARGS(...) \
    , __em_asm_sig_builder<__typeof__(__em_asm_make_type_tuple(__VA_ARGS__))>::buffer, ##__VA_ARGS__

template <typename a, typename b>
struct teplateSctruct {};

int main () {
    cout << MY_MACRO(3) << endl;

    char *str = "test";
    int num = 1;
    LOG("this is test __VA_ARGS__\r\n");
    LOG("this is %s __VA_ARGS__:%d\r\n", str, num);
	LOG("*******************");
    return 0;
}
