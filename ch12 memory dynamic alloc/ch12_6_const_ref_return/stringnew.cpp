#include <cstring>
#include "stringnew.h"

using std::cin;
using std::cout;


// init static
int String::num_strings = 0;

/*
* static 成员函数的定义
*/
int String::HowMany() {
    return num_strings;
}

String::String() {
    cout << "*******> constructor called:String::String()" << std::endl;
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}
String::String (const char *s) {
    cout << "*******> constructor called:String::String(const char *s)" << std::endl;
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str, s);
    num_strings++;
}
String::String(const String & st) {
    cout << "*******> constructor called:String::String(const String & st)" << std::endl;
    num_strings++;
    len = st.len;
    str = new char[len+1];
    std::strcpy(str, st.str);
}
/*
* 但是由于析构函数是没有参数的,那么从而无法通过参数的不同来达到重载多个析构函数的目的,从而析构函数只能有一个.
*/
String::~String() {
    cout << "*******> constructor called:String::~String()" << std::endl;
    --num_strings;
    delete [] str;
}


// overload operator
/*
* 运算符重载的定义
*/
 /**
 * 拷贝构造函数和赋值运算符
 *      拷贝构造函数使用传入对象的值生成一个新的对象的实例
 *      赋值运算符是将对象的值复制给一个已经存在的实例
 */ 
String & String::operator=(const String &st) {
    cout << "---> assignment called:String::operator=(const String &st)" << std::endl;
    if (this == &st) {
        return *this;
    }
    delete []str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}
String & String::operator=(const char *s) {
    cout << "---> assignment called:String::operator=(const char *s)" << std::endl;
    delete []str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}
char & String::operator[](int i) {
    cout << "===> char String::operator[](int i) called:" << std::endl;
    return str[i];
}
const char & String::operator[](int i) const {
    cout << "===> const char String::operator[](int i) const called:" << std::endl;
    return str[i];
}
bool operator<(const String &st, const String &st2) {
    cout << "===> bool operator<(const String &st, const String &st2) called:" << std::endl;
    return (std::strcmp(st.str, st2.str) < 0);
}
bool operator>(const String &st1, const String &st2) {
    cout << "===> bool operator>(const String &st1, const String &st2) called:" << std::endl;
    return st2 < st1; // 重载的运算符调用重载的运算符
}
bool operator==(const String &st, const String &st2) {
    cout << "===> bool operator==(const String &st, const String &st2) called:" << std::endl;
    return (std::strcmp(st.str, st2.str) == 0);
}
ostream & operator << (ostream &os, const String &st) {
    cout << "===> ostream & operator << (ostream &os, const String &st) called:" << std::endl;
    os << st.str;
    return os;
}
istream & operator>> (istream &is, String &st) {
    cout << "===> istream & operator>> (istream &is, String &st) called:" << std::endl;
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is) st = temp;
    while(is && is.get() != '\n') continue;
    return is;
}
