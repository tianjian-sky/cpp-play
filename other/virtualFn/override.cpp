#include <vector>
#include <iostream>
#include <utility>
using namespace std;

/*
* 虚函数
* 根据引用对象的实际类型确定调用哪个方法。
* 父类引用或指针！！指向子类对象，调用虚方法后，则调用的是子类的方法
*/

class A {
    public:
        int a;
        int b;
        A (int a, int b): a(a), b(b) {
            cout << "Using A constructor" << a << ":" << b <<":" << endl;
        }; // 委托了构造函数
        A (int a): A(a, 0) {};
        void print(int a) {
            cout << "A print" << endl;
        };
        virtual void printV(int) {
             cout << "virtual A print" << endl;
        }
        virtual void printV2(int) {
             cout << "virtual2 A print" << endl;
        }
};
class B : public A {
    public:
        int c=999;
        // B (int a, int b, int c): A(a, b),c(c) {}
        // B (int a, int b): A(a,b) ,c(0) {
        //     cout << "Using B constructor" << endl;
        // }
        B (double da, double db): A(da,db) ,c(0) {}
        void print(int a) {
            cout << "B print" << endl;
        };
        void printV(int a) {
             cout << "virtual B print" << endl;
        }
        void printV2(double) {
             cout << "virtual2 B print" << endl;
        }
};
int main () {
    A a(1,2);
    B b(1,2);
    A aNormal = b;
    A* ab = &b;
    A& abRef = b;
    cout << "---" << endl;
    a.print(1);
    b.print(1);
    aNormal.print(1); // not Ref or Pointer, still A
    ab->print(1); // not virtual, still A
    abRef.print(1); // not virtual, still A
    cout << "---" << endl;
    a.printV(1);
    b.printV(1);
    aNormal.printV(1); // not Ref or Pointer, still A
    ab->printV(1); // B called
    abRef.printV(1); // B called
}
