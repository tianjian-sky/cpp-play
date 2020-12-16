#include <iostream>

// extern const int const_global; // error: undefined reference to `const_global'
extern const int extern_const_global;


using namespace std;


void readConst() {
    // cout << "Read const global:" << const_global << endl; // error: undefined reference to `const_global'
    cout << "Read extern const global:" << extern_const_global << endl;
}