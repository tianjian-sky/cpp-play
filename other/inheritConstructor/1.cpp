#include <vector>
#include <iostream>
#include <utility>
using namespace std;


/**
 * 委托构造函数
 * 
 * 有using:
 * 如果有完全与子类函数签名匹配的，就使用子类的，否则使用父类的
 *  无using:
 * 如果有完全与子类函数签名匹配的，就使用子类的，否则也尝试使用子类的
*/

class A {
    public:
        int a;
        int b;
        A (int a, int b): a(a), b(b) {
            cout << "Using A constructor" << a << ":" << b <<":" << endl;
        }; // 委托了构造函数
        A (int a): A(a, 0) {};
};
class B : public A {
    public:
    /**
     * 委托构造函数
     * 
     * 有using:
     * 如果有完全与子类函数签名匹配的，就使用子类的，否则使用父类的
     *  无using:
     * 如果有完全与子类函数签名匹配的，就使用子类的，否则也尝试使用子类的
    */
        using A::A;
        int c=999;
        // B (int a, int b, int c): A(a, b),c(c) {}
        // B (int a, int b): A(a,b) ,c(0) {
        //     cout << "Using B constructor" << endl;
        // }
        B (double da, double db): A(da,db) ,c(0) {
            cout << "Using B constructor" << endl;
        }
        void print() {
            cout << a << ":" << b << ":" << c << endl;
        }
};
int main () {
    cout << "-1--" << endl;
    B b(1,2); // 派生类没有匹配的，就使用基类的
    b.print();
    cout << "-2--" << endl;
    B b2(3.1,5.1);
    b2.print();
}