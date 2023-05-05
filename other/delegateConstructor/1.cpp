#include <vector>
#include <iostream>
#include <utility>
using namespace std;


/**
 * 委托构造函数
 * 
*/

template<class T>
class A {
    public:
        int a;
        int b;
        A (int a, int b): a(a), b(b) {}; // 委托了构造函数
        A (int a): A(a, 0) {};
};
int main () {
    A<int> a(1,2); // error: no matching constructor for initialization of 'A<int>'
    cout << a.a << ":" << a.b << endl;
}