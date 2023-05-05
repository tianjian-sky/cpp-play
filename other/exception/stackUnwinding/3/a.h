#include <iostream>

using namespace std;

class A {
    public:
        string msg;
        A(string msg) : msg(msg) {}
        ~A() {
            cout << msg << " destroyed." << endl;
        }
};

class Ex {
    public:
        string msg;
        Ex(string msg) : msg(msg) {}
        ~Ex() {
            cout << msg << "Ex handled." << endl;
        }
};

class Ex2 {
    public:
        string msg;
        Ex2(string msg) : msg(msg) {}
        ~Ex2() {
            cout << msg << "Ex2 handled." << endl;
        }
};