#include <iostream>

void swapr(int &a, int &b);
void swapp(int *p, int *q);
void swapv(int a, int b);

/**
* 将引用作为参数传递
*/
int main () {
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;
    int wallet12 = 300;
    int wallet22 = 350;
    int wallet13 = 300;
    int wallet23 = 350;

    cout << "wallet1 = $" << wallet1 << endl;
    cout << "wallet2 = $" << wallet2 << endl;

    cout << "using ref to swap values:" << endl;
    swapr(wallet1, wallet2);
    cout << "wallet1 = $" << wallet1 << endl;
    cout << "wallet2 = $" << wallet2 << endl;

    cout << "using pointers to swap values:" << endl;
    swapp(&wallet12, &wallet22);
    cout << "wallet1 = $" << wallet12 << endl;
    cout << "wallet2 = $" << wallet22 << endl;

    cout << "using values to swap values:" << endl;
    swapv(wallet13, wallet23);
    cout << "wallet1 = $" << wallet13 << endl;
    cout << "wallet2 = $" << wallet23 << endl;

    return 0; 
}

void swapr(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapp(int *p, int *q) {
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void swapv(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
