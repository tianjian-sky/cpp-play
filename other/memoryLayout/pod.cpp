/**
 * https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170#literal_types
 * 
 * 术语“布局”是指类、结构或联合类型的对象的成员在内存中的排列方式。 在某些情况下，布局由语言规范明确定义。 但是，当类或结构包含某些 C++ 语言功能（如虚拟基类、虚拟函数、具有不同访问控制的成员）时，编译器可以自由选择布局。 该布局可能会基于正在执行的优化而有所不同，并且在许多情况下，该对象甚至可能不会占用连续内存区域。
 * 例如，如果某个类具有虚拟函数，则该类的所有实例可能会共享单个虚拟函数表。 此类型非常有用，但它们也有限制。 由于布局未定义，因此无法将其传递到使用其他语言（例如 C）编写的程序，并且由于它们可能是非连续的，因此无法使用快速低级函数（例如 memcopy）对其进行可靠复制，或者通过网络对其进行序列化。
 * 标准库具有函数模板 is_trivial<T>、is_standard_layout<T> 和 is_pod<T>，这些模板可以确定某一给定类型是否属于某一给定类别。
*/

/**
 * POD 类型
 * 当某一类或结构同时为普通和标准布局时，该类或结构为 POD（简单旧数据）类型。 
 * 因此，POD 类型的内存布局是连续的，并且每个成员的地址都比在其之前声明的成员要高，以便可以对这些类型执行逐字节复制和二进制 I/O。 标量类型（例如 int）也是 POD 类型。 作为类的 POD 类型只能具有作为非静态数据成员的 POD 类型。
*/
#include <iostream>
#include <type_traits> //library containing is_trivial function 

using namespace std;


struct B
{
protected:
   virtual void Foo() {}
};

// Neither trivial nor standard-layout
struct A : B
{
   int a;
   int b;
   void Foo() override {} // Virtual function
};

// Trivial but not standard-layout
struct C
{
   int a;
private:
   int b;   // Different access control
};

// Standard-layout but not trivial
struct D
{
   int a;
   int b;
   D() {} //User-defined constructor
};

struct POD
{
   int a;
   int b;
};

int main () {
   cout << "A is trivial is " << is_trivial<A>() << endl; // false
   cout << "A is standard-layout is " << is_standard_layout<A>() << endl;  // false

   cout << "C is trivial is " << is_trivial<C>() << endl; // true
   cout << "C is standard-layout is " << is_standard_layout<C>() << endl;  // false

   cout << "D is trivial is " << is_trivial<D>() << endl;  // false
   cout << "D is standard-layout is " << is_standard_layout<D>() << endl; // true

   cout << "POD is trivial is " << is_trivial<POD>() << endl; // true
   cout << "POD is standard-layout is " << is_standard_layout<POD>() << endl; // true

   return 0;
}