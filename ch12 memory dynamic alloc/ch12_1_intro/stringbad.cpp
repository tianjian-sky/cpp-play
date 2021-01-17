#include <cstring>
#include "stringbad.h"

using std::cout;

/**
 * 不能在类声明中初始化静态成员变量，因为声明描述了如何分配内存，但是不分配内存
 * 静态类成员可以在类声明之外用单独的语句初始化，因为类静态成员是单独存储的，而不是对象的组成部分
 * 
*/

/*
* 例外：可以在类声明中初始化的静态成员
* 1）const整型 -std=c++11
* 2）枚举型 -std=c++11
*/
 
int StringBad::num_strings = 0;

StringBad::StringBad(const char * s) {
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str, s);
    num_strings ++;
    cout << num_strings << ":\"" << str << "\" object created\n";
}

StringBad::StringBad() {
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ":\"" << str << "\" default object created\n";
}

/**
 * 在构造函数中使用new来分配内存时，必须在相应的析构函数中使用delete来释放内存
*/
StringBad:: ~StringBad() {
    cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left \n";
    delete [] str;
}
std::ostream & operator << (std::ostream &os, const StringBad &st) {
    os << st.str;
    return os;
}