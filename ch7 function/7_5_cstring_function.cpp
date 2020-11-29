#include <iostream>
const int ARR_SIZE = 8;
using namespace std;

int c_int_str(const char * str, char ch);

int main () {

    char mmm[15] = "minimum";
    char * wail = "ululate";
    unsigned int ms = c_int_str(mmm, 'm');
    unsigned int us = c_int_str(wail, 'u');

    cout << ms << "m char in " << mmm << endl;
    cout << us << "u char in " << us << endl;
    return 0;
}

int c_int_str(const char * str, char ch) {

    unsigned int count = 0;
    while (*str) {
        if (ch === *str) {
            count ++;
        }
        str += 1;
    }
}

