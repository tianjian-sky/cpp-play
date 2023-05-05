
/*
能出现在赋值号左边的表达式称为“左值”，不能出现在赋值号左边的表达式称为“右值”。

C++11 新增了一种引用，可以引用右值，因而称为“右值引用”。无名的临时变量不能出现在赋值号左边，因而是右值。右值引用就可以引用无名的临时变量。
*/

/*
class A{};
A & rl = A();  //错误，无名临时变量 A() 是右值，因此不能初始化左值引用 r1
A && r2 = A();  //正确，因 r2 是右值引用
*/


/*
第 33 行重载了一个移动赋值号。它和第 19 行的复制赋值号的区别在于，其参数是右值引用。在移动赋值号函数中没有执行深复制操作，而是直接将对象的 str 指向了参数 s 的成员变量 str 指向的地方，然后修改 s.str 让它指向别处，以免 s.str 原来指向的空间被释放两次。

该移动赋值号函数修改了参数，这会不会带来麻烦呢？答案是不会。因为移动赋值号函数的形参是一个右值引用，则调用该函数时，实参一定是右值。右值一般是无名临时变量，而无名临时变量在使用它的语句结束后就不再有用，因此其值即使被修改也没有关系。

第 53 行，如果没有定义移动赋值号，则会导致复制赋值号被调用，引发深复制操作。临时无名变量String("this")是右值，因此在定义了移动赋值号的情况下，会导致移动赋值号被调用。移动赋值号使得 s 的内容和 String("this") 一致，然而却不用执行深复制操作，因而效率比复制赋值号高。

虽然移动赋值号修改了临时变量 String("this")，但该变量在后面已无用处，因此这样的修改不会导致错误。

第 46 行使用了 C++ 11 中的标准模板 move。move 能接受一个左值作为参数，返回该左值的右值引用。因此本行会用定义于第 28 行、以右值引用作为参数的移动构造函数来初始化 tmp。该移动构造函数没有执行深复制，将 tmp 的内容变成和 a 相同，然后修改 a。由于调用 MoveSwap 本来就会修改 a，所以 a 的值在此处被修改不会产生问题。

*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class String
{
public:
    char* str;
    String() : str(new char[1]) { str[0] = 0; }
    String(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    String(const String & s) {//复制构造函数
        cout << "copy constructor called" << endl;
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    String & operator = (const String & s) {//复制赋值号
        cout << "copy operator = called" << endl;
        if (str != s.str) {
            delete[] str;
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
        }
        return *this;
    }
    String(String && s) : str(s.str) { //移动构造函数
        cout << "move constructor called" << endl;
        s.str = new char[1];
        s.str[0] = 0;
    }
    String & operator = (String && s) { //移动赋值号
        cout << "move operator = called" << endl;
        if (str != s.str) {
            str = s.str;
            s.str = new char[1];
            s.str[0] = 0;
        }
        return *this;
    }
    ~String() { delete[] str; }
};
template <class T>
void MoveSwap(T & a, T & b) {
    T tmp(move(a));  //std::move(a) 为右值，这里会调用移动构造函数
    a = move(b);  //move(b) 为右值，因此这里会调用移动赋值号
    b = move(tmp);  //move(tmp) 为右值，因此这里会调用移动赋值号
}
int main()
{
    String s;
    s = String("this");  //调用移动赋值号
    cout << "* * * *" << endl;
    cout << s.str << endl;
    String s1 = "hello", s2 = "world";
    MoveSwap(s1, s2);  //调用一次移动构造函数和两次移动赋值号
    cout << s2.str << endl;
    return 0;
}