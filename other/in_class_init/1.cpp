#include <iostream>
using namespace std;

class A {
    public:
        int a = 1;
        int b = 2;
        A() {}
        A(int a, int b): a(a), b(b) {};
        void print () {
            cout << a << endl; // 1
        }

};

int main () {
   A a;
   A b(8,9);
   a.print();
   b.print();
}