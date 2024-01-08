#include <iostream>
#include <tuple>

using namespace std;

template<typename, typename = void> struct __em_asm_sig {};
template<> struct __em_asm_sig<float> { static const char value = 'd'; };
template<> struct __em_asm_sig<double> { static const char value = 'd'; };
template<> struct __em_asm_sig<char> { static const char value = 'i'; };
template<> struct __em_asm_sig<signed char> { static const char value = 'i'; };
template<> struct __em_asm_sig<unsigned char> { static const char value = 'i'; };
template<> struct __em_asm_sig<short> { static const char value = 'i'; };
template<> struct __em_asm_sig<unsigned short> { static const char value = 'i'; };
template<> struct __em_asm_sig<int> { static const char value = 'i'; };
template<> struct __em_asm_sig<unsigned int> { static const char value = 'i'; };
template<> struct __em_asm_sig<long> { static const char value = 'j'; };
template<> struct __em_asm_sig<unsigned long> { static const char value = 'j'; };
template<> struct __em_asm_sig<bool> { static const char value = 'i'; };
template<> struct __em_asm_sig<wchar_t> { static const char value = 'i'; };
template<> struct __em_asm_sig<long long> { static const char value = 'j'; };
template<> struct __em_asm_sig<unsigned long long> { static const char value = 'j'; };
template<typename T> struct __em_asm_sig<T*> { static const char value = 'p'; };

template<typename... Args>
struct __em_asm_type_tuple {};

// Instead of std::make_tuple
template<typename... Args>
__em_asm_type_tuple<Args...> __em_asm_make_type_tuple(Args... args) {
    return {};
};

// Explicit support for enums, they're passed as int via variadic arguments.
template<bool> struct __em_asm_if { };
template<> struct __em_asm_if<true> { typedef void type; };
template<typename T> struct __em_asm_sig<T, typename __em_asm_if<__is_enum(T)>::type> {
    static const char value = 'i';
};


template<typename>
struct __em_asm_sig_builder {};


template<typename... Args>
struct __em_asm_sig_builder<__em_asm_type_tuple<Args...> > {
  static const char buffer[sizeof...(Args) + 1];
};

template<typename... Args>
const char __em_asm_sig_builder<__em_asm_type_tuple<Args...> >::buffer[] = { __em_asm_sig<Args>::value..., 0 };




#define _EM_ASM_PREP_ARGS(...) \
    , __em_asm_sig_builder<__typeof__(__em_asm_make_type_tuple(__VA_ARGS__))>::buffer, ##__VA_ARGS__

#define LOG(...) std::make_tuple(__VA_ARGS__)

#define TEST_MACRO(va, ...) LOG(va _EM_ASM_PREP_ARGS(__VA_ARGS__))

template <typename a, typename b>
struct TeplateSctruct {
    a v1;
    b v2;
};

int main () {
    TeplateSctruct<int, int> s1 = {3, 4};
    TeplateSctruct<double, double> s2 = {3.222, 4.3333};
    cout << sizeof (s1) << endl;
    cout << sizeof (s2) << endl;
    auto tuple = TEST_MACRO("abcdefg", 2.22, 3.333);
    std::cout << "1st value = " << std::get < 0 > (tuple) << std::endl;
    std::cout << "2nd value = " << std::get < 1 > (tuple) << std::endl;
    std::cout << "3nd value = " << std::get < 2 > (tuple) << std::endl;
    std::cout << "4th value = " << std::get < 3> (tuple) << std::endl;
    const char* ch = std::get < 1> (tuple);
    for (int i = 0; i < 3; i++) {
        cout << ch << endl ;
        ch++;
    }

}