#include <iostream>
const int ARR_SIZE = 8;
using namespace std;

int c_int_str(const char * str, char ch);

char * build_str(char c, int n);

int main () {

    char mmm[15] = "minimum"; // char数组

    /**
    * c 风格字符串与常规char数组的一个重要区别是，字符串有内置的结束字符
    */
    char * wail = "ululate"; // 字符串的char指针

    // 字符串的三种表示法 1.char数组
    // 字符串的三种表示法 2.字符串的char指针
    // 字符串的三种表示法 3.字符串字面量
    unsigned int ms = c_int_str(mmm, 'm'); // 实际传递的是字符串的第一个地址
    unsigned int us = c_int_str(wail, 'u');
    unsigned int uc = c_int_str("china", 'c');

    cout << ms << "m char in " << mmm << endl; 
    cout << us << "u char in " << us << endl;  
    cout << uc << "c char in " << uc << endl;

    // 函数无法返回一个字符串，但是可以返回一个字符串地址
    cout << "return str: " << build_str('!', 20) << endl;

    return 0;
}

int c_int_str(const char * str, char ch) {

    unsigned int count = 0;
    while (*str) {
        if (*str == ch) {
        // if (*str === ch) { // error: expected primary-expression before '=' token
            count ++;
        }
        str += 1;
    }
    return count;
}

char * build_str(char c, int n) {
    char * pstr = new char [n+1];
    pstr[n] = '\0';
    while (n-- > 0) {
        pstr[n] = c;
    }
    return pstr;
}
