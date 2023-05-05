/**
 * https://learn.microsoft.com/zh-cn/cpp/cpp/initializing-classes-and-structs-without-constructors-cpp?view=msvc-170
 * 并不总是需要为 class 定义构造函数，特别是相对比较简单的类。 用户可以使用统一初始化来初始化 class 或 struct 的对象，如下面的示例所示：
 * 
 * 如果 class 或 struct 没有构造函数，请按 class 中声明的成员的顺序提供列表元素。 如果 class 具有构造函数，请按参数顺序提供元素。 如果类型具有隐式或显式声明的默认构造函数，你可以使用大括号初始化（具有空大括号）对其进行调用。
*/

/*
如果默认构造函数已显式声明，但标记为“已删除”，则无法使用空大括号初始化：
*/

/*
，当我们定义一个类的成员函数时，如果后面使用"=delete"去修饰，那么就表示这个函数被定义为deleted，也就意味着这个成员函数不能再被调用，否则就会出错。
*/

/*
初始化列表防止类型缩窄
*/

#include <string>
using namespace std;

class class_a {
public:
    class_a() {}
    class_a(string str) : m_string{ str } {}
    class_a(string str, double dbl) : m_string{ str }, m_double{ dbl } {}
double m_double;
string m_string;
};


class class_d {
public:
    float m_float;
    string m_string;
    wchar_t m_char;
};

class class_f {
public:
    class_f() = delete; // ，当我们定义一个类的成员函数时，如果后面使用"=delete"去修饰，那么就表示这个函数被定义为deleted，也就意味着这个成员函数不能再被调用，否则就会出错。
    class_f(string x): m_string { x } {}
    string m_string;
};

int main()
{
    class_a c1{};
    class_a c1_1;

    class_a c2{ "ww" };
    class_a c2_1("xx");

    // order of parameters is the same as the constructor
    class_a c3{ "yy", 4.4 };
    class_a c3_1("zz", 5.5);

    class_d d1{};
    class_d d1{ 4.5 };
    class_d d2{ 4.5, "string" };
    class_d d3{ 4.5, "string", 'c' };

    class_d d4{ "string", 'c' }; // compiler error
    class_d d5{ "string", 'c', 2.0 }; // compiler error

    class_f cf{ "hello" };
    class_f cf1{}; // compiler error C2280: attempting to reference a deleted function

    char ch = {1.1}; // 防止类型缩窄 implicit conversion from 'double' to 'char'
}