#include <iostream>
using std::cin;
using std::cout;
using std::endl;
/*
假设有以下代码
TextFile a, b;
a.Open( "FILE1.DAT" );
b.Open( "FILE2.DAT" );
b = a;

前面的代码可能表示“将 FILE1.DAT 的内容复制到 FILE2.DAT”，也可能表示“忽略 FILE2.DAT 并使 b 成为 FILE1.DAT 的另一个句柄”。必须将合适的复制语义附加到每个类，

如果不声明复制构造函数，编译器将为你生成成员的复制构造函数。 同样，如果不声明复制赋值运算符，编译器将为你生成成员的复制赋值运算符。 声明复制构造函数不会取消编译器生成的复制赋值运算符，反之亦然。 如果实现其中任一方法，我们建议也实现另一个。 实现这两者时，代码的含义是明确的。

// spec1_copying_class_objects.cpp
class Window
{
public:
    Window( const Window& );            // Declare copy constructor.
    Window& operator=(const Window& x); // Declare copy assignment.
    // ...
};

int main()
{
}

*/

/*
在C++中，下面几个场景中,拷贝构造函数会被调用：

一个对象需要通过另一个对象进行初始化
一个对象以值传递的方式作为参数传入函数
一个对象以值传递的方式作为返回值从函数返回

*/

/*
尽可能创建复制构造函数的参数 const ClassName& 的类型。 这可防止复制构造函数意外更改复制的对象。 它还允许从 const 对象复制。
*/

/*
若要实现移动语义，通常可以向类提供“移动构造函数”，或者提供移动赋值运算符 (operator=)。 
其源是右值的复制和赋值操作随后会自动利用移动语义。 
与默认复制构造函数不同，编译器不提供默认移动构造函数。 有关如何编写和使用移动构造函数详细信息，

*/

/*
当初始化器为纯右值时，通常会优化掉 (C++17 前)始终不会进行 (C++17 起)对移动构造函数的调用
*/

class A {
    public:
        int a;
        std::string name;
        A (int num1, std::string name) : a(num1), name(name) {
            cout << "A construct" << endl;
        };
        ~A () {
            cout << "A destruct:" << name << endl;
        };
        A (const A& input) { // Declare copy constructor.
            /*
                cannot assign to variable 'input' with const-qualified type 'const A &'
                尽可能创建复制构造函数的参数 const ClassName& 的类型。 这可防止复制构造函数意外更改复制的对象。 它还允许从 const 对象复制。
            */
            // input.a = 100; // cannot assign to variable 'input' with const-qualified type 'const A &'
            a = input.a;
            name = input.name + "_copy";
            cout << "A Copy" << endl;
        }
        // 移动构造函数
        A (const A&& input) { // Declare copy constructor.
            /*
                cannot assign to variable 'input' with const-qualified type 'const A &'
                尽可能创建复制构造函数的参数 const ClassName& 的类型。 这可防止复制构造函数意外更改复制的对象。 它还允许从 const 对象复制。
            */
            // input.a = 100; // cannot assign to variable 'input' with const-qualified type 'const A &'
            a = input.a;
            name = input.name + "_move";
            cout << "A move" << endl;
        }
        A& operator=(const A& input) { // Declare 移动赋值运算符
            if (this == &input) {
                cout << "Assignment intpu address == current address" << endl;
                return *this;
            }
            a = input.a;
            name = input.name + "_assignment";
            cout << "A assign" << endl;
            return *this;
        }
};

int main () {
    A* pa = new A(99, "peter");
    cout << "-----" << endl;
    A* pa_2 = new A(*pa);
    cout << "-----" << endl;
    A* pa_3 = new A(99, "mike");
    cout << "-----" << endl;
    *pa_3 = *pa_2;
    cout << "-----" << endl;
    A p5 = (A&&)pa_3;
    cout << "-----" << endl;
    delete pa_2;
    delete pa_3;
    delete pa;
}