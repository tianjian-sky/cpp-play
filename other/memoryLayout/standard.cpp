/**
 * https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170#literal_types
 * 
 * 术语“布局”是指类、结构或联合类型的对象的成员在内存中的排列方式。 在某些情况下，布局由语言规范明确定义。 但是，当类或结构包含某些 C++ 语言功能（如虚拟基类、虚拟函数、具有不同访问控制的成员）时，编译器可以自由选择布局。 该布局可能会基于正在执行的优化而有所不同，并且在许多情况下，该对象甚至可能不会占用连续内存区域。
 * 例如，如果某个类具有虚拟函数，则该类的所有实例可能会共享单个虚拟函数表。 此类型非常有用，但它们也有限制。 由于布局未定义，因此无法将其传递到使用其他语言（例如 C）编写的程序，并且由于它们可能是非连续的，因此无法使用快速低级函数（例如 memcopy）对其进行可靠复制，或者通过网络对其进行序列化。
 * 标准库具有函数模板 is_trivial<T>、is_standard_layout<T> 和 is_pod<T>，这些模板可以确定某一给定类型是否属于某一给定类别。
*/

/**
 * 标准布局类型
 * 当类或结构不包含某些 C++ 语言功能（例如无法在 C 语言中找到的虚拟函数），并且所有成员都具有相同的访问控制时，该类或结构为标准布局类型。 可以在内存中对其进行复制，并且布局已经过充分定义，可以由 C 程序使用。 标准布局类型可以具有用户定义的特殊成员函数。 此外，标准布局类型还具有以下特征：
    
    没有虚拟函数或虚拟基类
    所有非静态数据成员都具有相同的访问控制
    类类型的所有非静态成员均为标准布局
    所有基类都为标准布局
    没有与第一个非静态数据成员类型相同的基类。

    满足以下条件之一：
        最底层派生类中没有非静态数据成员，并且具有非静态数据成员的基类不超过一个，或者
        没有含非静态数据成员的基类
*/
#include <iostream>
#include <type_traits> //library containing is_trivial function 

using namespace std;


struct SL
{
   // All members have same access:
   int i;
   int j;
   SL(int a, int b) : i(a), j(b) {} // User-defined constructor OK
};

int main () {
    cout << "trivial:" << is_trivial<SL>::value << endl; 
    cout << "standard:" << is_standard_layout<SL>::value << endl; 
    cout << "pod:" << is_pod<SL>::value << endl;  // is_pod deprecated in c++20
}