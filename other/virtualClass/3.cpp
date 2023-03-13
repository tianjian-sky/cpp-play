/*
 * 虚基类

 * 1. 在基类是虚的时，禁止信息通过中间类自动传递给虚基类
 * 2. 虚基类子对象是由最远派生类的构造函数通过调用虚基类的构造函数进行初始化的。
 * 3.派生类的构造函数的成员初始化列表中必须列出对虚基类构造函数的调用；如果未列出，则表示使用该虚基类的缺省构造函数。
 * 4. 在一个成员初始化列表中同时出现对虚基类和非虚基类构造函数的调用时，虚基类的构造函数先于非虚基类的构造函数执行。
 * 5.从虚基类直接或间接派生的派生类中的构造函数的成员初始化列表中都要列出对虚基类构造函数的调用。但仅仅用建立对象的最远派生类的构造函数调用虚基类的构造函数，而该派生类的所有基类中列出的对虚基类的构造函数的调用在执行中被忽略，从而保证对虚基类子对象只初始化一次。
 */

/*
虚基类，非虚基类混合
*/
#include <iostream>
using namespace std;
class A {
    public:
        int a;
        A (int num1) :a(num1) {}
};

class B : virtual public A {
    public:
        int b;
        B (int num1, int num2) :A(num1), b(num2) {}
};

class C : virtual public A {
    public:
        int c;
        C (int num1, int num2) :A(num1), c(num2) {}
};

class D : virtual public A {
    public:
        int d;
        D (int num1, int num2) :A(num1), d(num2) {}
};

class E : public B, public C, public D {
    public: 
        int e;
        // 禁止信息通过中间类自动传递给虚基类
        // error: constructor for 'D' must explicitly initialize the base class 'A' which does not have a default constructor
        // D (int num1, int num2, int num3, int num4, int num5) :B(num1, num2), C(num3, num4),d (num5) {}
        E (int num1, int num2, int num3, int num4, int num5, int num6, int num7) :B(num1, num2), C(num3, num4), D(num5, num6), e (num7), A (999) {}
};

int main () {
    A* pa = new A(1);
    B* pb = new B(2, 3);
    C* pc = new C(4, 5);
    D* pd = new D(6, 7, 8, 9, 10);
    cout << pa->a << endl;
    cout << pb->a << ":" << pb->b << endl;
    cout << pc->a << ":" << pc->c << endl;
    // cout << pd->a << endl; // member 'a' found in multiple base-class subobjects of type 'A':
    cout << static_cast<B*>(pd)->a << ":" << static_cast<B*>(pd)->b << ":" << pd->d << endl; // member 'a' found in multiple base-class subobjects of type 'A':
    cout << static_cast<C*>(pd)->a << ":" << static_cast<C*>(pd)->c << ":" << pd->d << endl;
}

