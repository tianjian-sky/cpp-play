#include <iostream>
using namespace std;
/*

 public：可以被该类中的函数、子类的函数、友元函数访问，也可以由该类的对象访问；
protected：可以被该类中的函数、子类的函数、友元函数访问，但不可以由该类的对象访问；
private：可以被该类中的函数、友元函数访问，但不可以由子类的函数、该类的对象、访问。

*/

/*

基类中      继承方式             子类中

public     ＆ public继承        => public
public     ＆ protected继承     => protected    
public     ＆ private继承       => private

protected  ＆ public继承        => protected
protected  ＆ protected继承     => protected    
protected  ＆ private继承       => private

private    ＆ public继承        => 子类无权访问
private    ＆ protected继承     => 子类无权访问
private    ＆ private继承       => 子类无权访问
*/

class A {
    public:
        A (int a, int b, int c, int d, int e):a(a), b(b), c(c), d(d), e(e) {} // member initializer 'd' does not name a non-static data member or base class
        int a;
        int b;
        int c;
        // void setD(int d) {
        //     d = d;
        // }
    protected:
        int d;
    private: 
        int e;
};

class B: public A {
    public:
        B (int a, int b, int c, int d, int e):A(a, b, c, d, e) {} 
        void testProtected() {
            cout <<d<< endl;
        }
        // void testPrivate() { // private：可以被该类中的函数、友元函数访问，但不可以由子类的函数、该类的对象、访问。
        //     cout <<e<< endl;
        // }
};