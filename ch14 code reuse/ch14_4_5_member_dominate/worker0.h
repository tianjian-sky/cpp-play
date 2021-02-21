#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include <string>

class A {
    public:
        short q() {return 1;}
};

class B {
    public:
        int q() {return 2;}
};

/*
* 名称支配：
* 派生类中的名称，优于直接或间接祖先类中的名称
*
*/

class C : public A, public B {
    public: 
        void getQ() {
            //std::cout << "Q is:" << q() << std::endl; // error: reference to 'q' is ambiguous
            std::cout << "Q from A is:" << A::q() << std::endl;
            std::cout << "Q from B is:" << B::q() << std::endl;
        }
};

/*
* 名称支配：
* 派生类中的名称，优于直接或间接祖先类中的名称
*
*/

class A2 {
    private:
        char m() {return 'a';}
    public:
        short q() {return 1;}
};

class B2 {
    public:
        int q() {return 2;}
};

class C2 : virtual public A2, virtual public B2 {
    public: 
};
class F2 {
    public:
        char m() {return 'b';}
};

class D2 : public C2, public F2 {

    public:
        long q() {return 3;}
        void getQ() {
            std::cout << "Q is:" << q() << std::endl;
        }
        /*
        * 名称支配规则与访问规则无关，即使是基类的private的成员。
        */
        void getM() {
            std::cout << "M is:" << m() << std::endl; // error: reference to 'm' is ambiguous
        }
};


#endif