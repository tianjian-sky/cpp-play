#include <iostream>

/**
* 函数模板：使用泛型来定义参数
* 模板不会缩短可执行程序
* 1. 重载的模板
*/

template <typename T>
void Swap(T &a, T &b);

template <typename T>
void Swap(T *a, T *b, int n);

void show(int a[]);
const int Lim = 8;

int main () {
    using namespace std;
    int i = 10, j = 20;
    cout << "i,j=" << i << " , " << j << endl;
    cout << "Using compile generated int swapper:" << endl;
    Swap(i, j);
    cout << "Now i,j=" << i << " , " << j << endl;

    int d1[Lim] = {0,7,0,4,1,7,7,6};
    int d2[Lim] = {0,7,2,0,1,9,6,9};
    cout << "Original arrays:" << endl;
    show(d1);
    show(d2);
    Swap(d1, d2, Lim);
    cout << "Swapped arrays:" << endl;
    show(d1);
    show(d2);

    return 0; 
}

template <typename T>
void Swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Swap(T *a, T *b, int n) {
    T temp;
    for (int i = 0; i < n; i++) {
        // temp = *(a + i); //  error: invalid conversion from 'int' to 'int*'
        // a = *(b + i);
        // b = temp;
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void show(int a[]) {
    using namespace std;
    cout << a[0] << a[1] << "/";
    cout << a[2] << a[3] << "/";
    for (int i = 4; i < Lim; i++) {
        cout << a[i];
    }
    cout << endl;
}