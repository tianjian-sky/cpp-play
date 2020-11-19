#include <iostream>
using namespace std;

int main() {
    long *pt = new long[100];

    char *ps1 = "hello";

    char * ps2 = "world";

    long tell[100];

    cout << tell << endl;
    cout << &tell[0] << endl;
    cout << &tell << endl;
    cout << tell+1 << endl;
    cout << &tell+1 << endl;
    cout << ps1 << endl;
    cout << ps2 << endl;
    return 0;
}