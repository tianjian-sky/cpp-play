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
        A (int a, int b, int c, int d, int e):a(a), b(b), c(c), d(d), e(e) {}
        int a;
        int b;
        int c;
        class C_a {};
        void testClass() {
            new C_a();
            new C_b();
            new C_c();
        }
    protected:
        int d;
        class C_b {};
    private: 
        int e;
        class C_c {};
};

class B: public A {
    public:
        B (int a, int b, int c, int d, int e):A(a, b, c, d, e) {} 
        void testProtected() {
            cout <<d<< endl;
        }
        void testPrivate() { // private：可以被该类中的函数、友元函数访问，但不可以由子类的函数、该类的对象、访问。
            cout <<e<< endl;
        }
        void testClass() {
            new C_a();
            new C_b();
            new C_c();
        }
};

class C: protected A {
    public:
        C (int a, int b, int c, int d, int e):A(a, b, c, d, e) {} 
        void testPublic() {
            cout <<a<< endl;
        }
        void testProtected() {
            cout <<d<< endl;
        }
        void testPrivate() { // private：可以被该类中的函数、友元函数访问，但不可以由子类的函数、该类的对象、访问。
            cout << e << endl;
        }
        void testClass() {
            new C_a();
            new C_b();
            new C_c();
        }
};

class D: private A {
    public:
        D (int a, int b, int c, int d, int e):A(a, b, c, d, e) {} 
        void testProtected() {
            cout <<d<< endl;
        }
        void testPrivate() { // private：可以被该类中的函数、友元函数访问，但不可以由子类的函数、该类的对象、访问。
            cout <<e<< endl;
        }
        void testClass() {
            new C_a();
            new C_b(); // protected => protected
            new C_c();
        }
};

int main () {
    A a(9,8,7,5,6);
    B b(1,2,3,4, 5);
    C c(1,2,3,4, 5);
    D d(1,2,3,4, 5);
    cout << a.a << endl;
    cout << a.d << endl; // protected：可以被该类中的函数、子类的函数、友元函数访问，但不可以由该类的对象访问；
    cout << b.a << endl;
    cout << b.d << endl;
    cout << b.e << endl;
    cout << c.a << endl;
    b.testProtected();
    b.testPrivate(); // private：可以被该类中的函数、友元函数访问，但不可以由子类的函数、该类的对象、访问
    c.testProtected();
    c.testPrivate(); // private：可以被该类中的函数、友元函数访问，但不可以由子类的函数、该类的对象、访问。
    d.testProtected();
    d.testPrivate(); // private：可以被该类中的函数、友元函数访问，但不可以由子类的函数、该类的对象、访问
    
    // 访问限定符来访问
    new A::C_a();
    new A::C_b(); // protected的内嵌类不可在外部通过类限定符访问
    new A::C_c(); // private的内嵌类不可在外部通过类限定符访问
}