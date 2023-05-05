/**
 * https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170#literal_types
 * 
 * 术语“布局”是指类、结构或联合类型的对象的成员在内存中的排列方式。 在某些情况下，布局由语言规范明确定义。 但是，当类或结构包含某些 C++ 语言功能（如虚拟基类、虚拟函数、具有不同访问控制的成员）时，编译器可以自由选择布局。 该布局可能会基于正在执行的优化而有所不同，并且在许多情况下，该对象甚至可能不会占用连续内存区域。
 * 例如，如果某个类具有虚拟函数，则该类的所有实例可能会共享单个虚拟函数表。 此类型非常有用，但它们也有限制。 由于布局未定义，因此无法将其传递到使用其他语言（例如 C）编写的程序，并且由于它们可能是非连续的，因此无法使用快速低级函数（例如 memcopy）对其进行可靠复制，或者通过网络对其进行序列化。
 * 标准库具有函数模板 is_trivial<T>、is_standard_layout<T> 和 is_pod<T>，这些模板可以确定某一给定类型是否属于某一给定类别。
*/

/**
 * 普通类型
 * “普通”意味着构造函数/运算符/析构函数并非用户提供，并且属于存在以下情况的类
 * 
 * 没有虚拟函数或虚拟基类，

 * 没有具有相应非普通构造函数/运算符/析构函数的基类

 * 没有具有相应非普通构造函数/运算符/析构函数的类类型的数据成员
*/
#include <iostream>
#include <type_traits> //library containing is_trivial function 

using namespace std;


struct Trivial
{
   int i;
private:
   int j;
};

struct Trivial2
{
   int i;
   Trivial2(int a, int b) : i(a), j(b) {}
   Trivial2() = default;
private:
   int j;   // Different access control
};

int main () {
    cout << "trivial:" << is_trivial<Trivial>::value << endl; 
    cout << "standard:" << is_standard_layout<Trivial>::value << endl; 
    cout << "pod:" << is_pod<Trivial>::value << endl; 
}