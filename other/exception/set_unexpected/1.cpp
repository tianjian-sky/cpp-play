
#include "iostream"
#include <string>
#include <exception>
using namespace std;

/*
unexpected exception
意外异常，未在catch表中出现，程序首先调用unexpected(),默认情况下，unexpected()会调用terminate()，unexpected()会调用abort()，可以改变这个默认行为
*/

class A {
    public:
        string msg;
        A (string msg = "A") : msg(msg) {}
};

class B {
    public:
        string msg;
        B (string msg = "B") : msg(msg) {}
};

void myUnExpected () {
    cout << "un expect handler" << endl;
    throw A();
}
int main () {
    set_unexpected(myUnExpected);
    try {
        throw B();
    } catch (A & ea) {
        cout << "captured ex" << endl;
    }
    cout << "Done" << endl;
};