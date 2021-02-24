#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"
using std::cin;
using std::cout;
using std::endl;

int main () {
    ArrayTp<int, 5> arr(999);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << ";" << endl;
    }
    return 0;
}