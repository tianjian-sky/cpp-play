/**
 * dynamic_cast
 * 
 * https://learn.microsoft.com/zh-cn/cpp/cpp/dynamic-cast-operator?view=msvc-170
 * 
    对指向装箱枚举的基础类型的指针的 dynamic_cast 将在运行时失败，返回 0 而不是转换后的指针。

    如果 type-id 是指向值类型的内部指针，在运行时强制转换失败时，dynamic_cast 将不再引发异常。 强制转换现在将返回 0 指针值，而不是引发异常。
 
     
    基类一定要是多态型的，必须有一个虚方法，否则不能dynamic_case
    https://stackoverflow.com/questions/15114093/getting-source-type-is-not-polymorphic-when-trying-to-use-dynamic-cast/15114118
    You need at least a virtual function - typically, if no others are suitable, the destructor:

    在C++的面对对象思想中，虚函数起到了很关键的作用，当一个类中拥有至少一个虚函数，那么编译器就会构建出一个虚函数表(virtual method table)来指示这些函数的地址，假如继承该类的子类定义并实现了一个同名并具有同样函数签名（function siguature）的方法重写了基类中的方法，那么虚函数表会将该函数指向新的地址。此时多态性就体现出来了：当我们将基类的指针或引用指向子类的对象的时候，调用方法时，就会顺着虚函数表找到对应子类的方法而非基类的方法。
当然虚函数表的存在对于效率上会有一定的影响，首先构建虚函数表需要时间，根据虚函数表寻到到函数也需要时间。
因为这个原因如果没有继承的需要，一般不必在类中定义虚函数。但是对于继承来说，虚函数就变得很重要了，这不仅仅是实现多态性的一个重要标志，同时也是dynamic_cast转换能够进行的前提条件。

dynamic_cast 用于类继承层次间的指针或引用转换。主要还是用于执行“安全的向下转型（safe downcasting）”，也即是基类对象的指针或引用转换为同一继承层次的其他指针或引用。
至于“向上转型”（即派生类指针或引用类型转换为其基类类型），本身就是安全的，尽管可以使用dynamic_cast进行转换，但这是没必要的， 普通的转换已经可以达到目的。
“向下转型”的前提条件：被转换对象必须是多态类型（必须公有继承自其他类，或者有虚函数）。

“向下转型”有两种情况。

一种是基类指针所指对象是派生类类型的，这种转换是安全的；
另一种是基类指针所指对象为基类类型，在这种情况下dynamic_cast在运行时做检查，转换失败，返回结果为0；
————————————————
版权声明：本文为CSDN博主「有温度的程序员」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44218779/article/details/125001020
 
 * 
 */
#include <iostream>
using std::cout;
using std::endl;

/*
        A
      /   \
    B       C
      \    /
        D 
*/
class A {virtual void f();};
class B : public A {virtual void f();};
class C : public A {virtual void f();};
class D : public B, public C {virtual void f();};


int main () {
    D* pd = new D;
    A* pa = dynamic_cast<A*>(pd);   // error: 'A' is an ambiguous base of 'D'
    B* pb = dynamic_cast<B*>(pd);   // first cast to B
    A* pa2 = dynamic_cast<A*>(pb);   // ok: unambiguous
}