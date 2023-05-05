/*
，当我们定义一个类的成员函数时，如果后面使用"=delete"去修饰，那么就表示这个函数被定义为deleted，也就意味着这个成员函数不能再被调用，否则就会出错。
*/

#include <string>
using namespace std;


class class_f {
public:
    class_f() = delete; // ，当我们定义一个类的成员函数时，如果后面使用"=delete"去修饰，那么就表示这个函数被定义为deleted，也就意味着这个成员函数不能再被调用，否则就会出错。
    class_f(string x): m_string { x } {}
    string m_string;
};

int main()
{
    class_f cf{ "hello" };
    class_f cf1{}; // compiler error C2280: attempting to reference a deleted function
}