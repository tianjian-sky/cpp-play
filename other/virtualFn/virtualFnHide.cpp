#include <vector>
#include <iostream>
#include <utility>
using namespace std;

/*
* 虚函数
* 根据引用对象的实际类型确定调用哪个方法。
* 父类引用或指针！！指向子类对象，调用虚方法后，则调用的是子类的方法
*/

/*
* 虚函数 协变重写，指的是子类重写虚函数，返回值是父类虚函数返回值的协变类型，这样是符合虚函数重写规则的
*/


/*
虚函数隐藏：
在子类中对基类虚函数进行重新定义，同名但不同参数列表，此时，原来的虚函数将不会被重载，而是会被隐藏
*/

class A {
    public:
        int a;
        int b;
        A (int a, int b): a(a), b(b) {
            cout << "Using A constructor" << a << ":" << b <<":" << endl;
        }; // 委托了构造函数
        A (int a): A(a, 0) {};
        virtual void printV(int) {
             cout << "virtual A print" << endl;
        }
        virtual A* printV2(int) {
             cout << "virtual A print2" << endl;
             return this;
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
        void printV(char ch) {
             cout << "virtual B print no override" << endl;
        }
        B* printV2(int) {
             cout << "virtual B print2" << endl;
             return this;
        }
};
int main () {
    A a(1,2);
    B b(1,2);
    A aNormal = b;
    A* ab = &b;
    a.printV(1);
    cout << "---" << endl;
    aNormal.printV(1);
    aNormal.printV('a');
    cout << "---" << endl;
    b.printV(1); // 仍然调用的子类的方法，原有的虚函数被隐藏了
    b.printV('a');
    cout << "---" << endl;
    ab->printV(1);
    cout << "---coviriant overide" << endl;
    ab->printV2(1);
    // cout << bb->c << endl;
}
