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
    /**
     * 这样写不保险，因为可能导致默认的拷贝构造函数调用时，静态变量没有++
     */
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
    /**
     * 这样写不保险
     * 1.可能导致默认的拷贝构造函数调用时，重复删除之前已经析构了的对象的变量地址，造成运行时错误
     * 2.可能把被复制而未析构的对象的变量地址删除了，导致被复制对象行为异常
     */
    delete [] str;
}

StringBad:: StringBad(const StringBad &sb) {
    cout << "-------->Copy constructor called!!";
    num_strings++;
    len = sb.len;
    str = new char[len + 1];
    std::strcpy(str, sb.str);
    cout << num_strings << ": \"" << str << "\" object created \n";
}
std::ostream & operator << (std::ostream &os, const StringBad &st) {
    os << st.str;
    return os;
}
/*
* 赋值运算符重载
* A = B 定义为A类的成员函数
*/
StringBad & StringBad::operator = (StringBad &sb) { // 赋值运算符重载
    /*
    * 牢记 this 是一个指针
    */
    cout << ";;;;;;;;;;;;>Assignmenmt called!!" << std::endl;
    if (this == &sb) { // this 是一个指针，因此需要传地址
        return *this;
    }
    delete [] str;
    len = sb.len;
    str = new char[len + 1];
    std::strcpy(str, sb.str);
    return *this;
}