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
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}
String::String (const char *s) {
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str, s);
    num_strings++;
}
String::String(const String & st) {
    num_strings++;
    len = st.len;
    str = new char[len+1];
    std::strcpy(str, st.str);
}
String::~String() {

}
// overload operator
/*
* 运算符重载的定义
*/
String & String::operator=(const String &) {

}
String & String::operator=(const char *) {

}
char & String::operator[](int i) {

}
const char & String::operator[](int i) const {

}
bool operator<(const String &st, const String &st2) {

}
bool operator>(const String &stl, const String &st2) {

}
bool operator==(const String &st, const String &st2) {

}
ostream & operator << (ostream &os, const String &st) {

}
istream & operator>> (istream &is, String &st) {

}
