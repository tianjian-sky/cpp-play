/*
 * 虚基类

 * 1. 在基类是虚的时，禁止信息通过中间类自动传递给虚基类
 */
#include <iostream>
using namespace std;
class A {
    public:
        int a;
        A (int num1) :a(num1) {}
};

class B : public A {
    public:
        int b;
        B (int num1, int num2) :A(num1), b(num2) {}
};

class C : public A {
    public:
        int c;
        C (int num1, int num2) :A(num1), c(num2) {}
};

class D : public B, public C {
    public: 
        int d;
        D (int num1, int num2, int num3, int num4, int num5) :B(num1, num2), C(num3, num4),d (num5) {}
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

