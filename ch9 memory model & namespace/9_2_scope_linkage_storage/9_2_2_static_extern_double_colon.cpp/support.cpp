#include <iostream>

using namespace std;

extern double warning;

void update(double dt);
void local();

void update(double dt) {
    extern double warning; // extern： 此变量/函数是在别处定义的，要在此处引用
    warning += dt;
    cout << "Update global warning to " << warning << " degrees." << endl;
}

void local() {
    double warning = 0.8;
    cout << "Local warning = " << warning << " degrees." << endl;
    cout << "But global warning = " << ::warning << " degrees." << endl;
}