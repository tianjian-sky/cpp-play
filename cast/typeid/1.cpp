/**
 *
 * typeid 运算符允许在运行时确定对象的类型。

typeid 的结果是 const type_info&。 该值是对表示 type-id 或 expression 的类型的 type_info 对象的引用，具体取决于所使用的 typeid 的形式。 有关详细信息，请参阅 type_info 类。

typeid 运算符在应用于多态类类型的左值时执行运行时检查，其中对象的实际类型不能由提供的静态信息确定。 此类情况是：

    对类的引用

    使用 * 取消引用的指针

    带下标的指针（即 [ ]）。（请注意，通常情况下，将下标与指向多态类型的指针一起使用不安全。）

    此外，必须取消引用指针以使用它指向的对象。 如果未取消引用指针，结果将是指针的 type_info，而不是它指向的内容。 例如：

*/
#include <iostream>
// #include <typeinfo.h>

class Base
{
public:
    virtual void vvfunc() {}
};

class Derived : public Base
{
};

using namespace std;
int main()
{
    Derived *pd = new Derived;
    Base *pb = pd;
    cout << typeid(pb).name() << endl;  // prints "class Base *"
    cout << typeid(*pb).name() << endl; // prints "class Derived"
    cout << typeid(pd).name() << endl;  // prints "class Derived *"
    cout << typeid(*pd).name() << endl; // prints "class Derived"
    delete pd;
}