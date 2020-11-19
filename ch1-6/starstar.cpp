#include <iostream>
using namespace std;

int main() {
    int a = 100;
    
    int *r = &a;
    int ** c = &r;

    cout << r << endl;
    cout << &r << endl;
    cout << *r << endl;

    cout << c << endl;
    cout << *c << endl;
    cout << **c << endl;
    


    return 0;
}