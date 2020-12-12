#include <iostream>
#include <string>
using namespace std;

/**
*
* 函数重载：同名函数，参数列表不同，返回值相同！！
* 特征标： 参数列表，函数签名。
* 函数签名是指函数的参数个数，参数类型以及参数的顺序。
* 重载的定义是：在同一作用域内函数签名不同但函数名相同的函数互为重载。
*/

void print(const char *str, int width);
void print(double d, int width);
void print(long l, int width);
void print(int i, int width);
void print(const char *str);

/*
* 1.两个函数的名称相同，签名相同，则返回值必须不同，否则编译报error
* 两个函数的名称相同，签名相同，则返回值必须不同，
* 否则编译报error: ambiguating new declaration of 'double gronk(int, float)'
*/
// long gronk(int n, float m);
// double gronk(int n, float m);// error: ambiguating new declaration of 'double gronk(int, float)'

/* 
* 3. 类型引用和类型本身看作用一个特征标
*/
// double cube(double x);
// double cube(double & x);

/*
* 4. 匹配函数时，不区分const和非const
* error: redefinition of 'double test(int)'
*/
// double test(int x);
// double test(const int x); // error: redefinition of 'double test(int)'

/**
* 5. 不强制转换就能匹配多个匹配结果，取最匹配的结果
*/

void staff (double & rs);
void staff (const double & rs);
void staff (double && rs); // && 右值引用

int func(int a);
double func(char b);

int main () {
    
    /**
    * 1.两个函数的名称相同，签名相同，则返回值必须不同，否则编译报error
    * 2. 不匹配任何函数签名，c++尝试使用类型转换进行强制匹配，若此时可能有多个可能的匹配结果，编译报error
    * 3. 类型引用和类型本身看作用一个特征标,
    * 4. 匹配特征标，不区分const和非const
    * 5. 不强制转换就能匹配多个匹配结果，取最匹配的结果
    */

    print ("Pancakes", 15);
    print ("Syrup");
    print(1999.0, 10);
    print(1999, 12);
    print(1999L, 15);

    /**
    * 2. 不匹配任何函数签名，c++尝试使用类型转换进行强制匹配
    * 若此时可能有多个可能的匹配结果，编译错误：error: call of overloaded 'print(unsigned int&, int)' is ambiguous。candidate:...candidate:...
    */
    // unsigned int year = 3210; // error: call of overloaded 'print(unsigned int&, int)' is ambiguous
    // print(year, 6);


    /* 
    * 3. 类型引用和类型本身看作用一个特征标,
    * error: call of overloaded 'cube(double&)' is ambiguous
    */
    // double d = 222.2;
    // double &d_ref = d;
    // cube(d);
    // cube(d_ref); // error: call of overloaded 'cube(double&)' is ambiguous


    /*
    * 4. 匹配函数时，不区分const和非const
    */
    // int t2 = 99;
    // test(t2);
    int i = 1;
    double d = 2.1;
    char c = '3';
    func(1);
    func(c);

    cout << "\n\nTesting match priority:\n" << endl;

    double d1 = 55.5;
    const double d2 = 32.0;

    /*
    * 5. 不强制转换就能匹配多个匹配结果，取最匹配的结果
    */
    staff(d1);
    staff(d2);
    staff(d1 + d2); // 传入rvalue

    return 0; 
}

void print(const char *str, int width) {
    cout << "print 1: void print(const char *str, int width)" << endl;
}
void print(double d, int width) {
    cout << "print 2: void print(double d, int width)" << endl;
}
void print(long l, int width) {
    cout << "print 3: void print(long l, int width)" << endl;
}
void print(int i, int width) {
    cout << "print 4: void print(int i, int width)" << endl;
}
void print(const char *str) {
    cout << "print 5: void print(const char *str)" << endl;
}

// long gronk(int n, float m) {
//     long v = 1L;
//     cout << "gronk 1: long gronk(int n, float m)" << endl;
//     return v;
// }
// double gronk(int n, float m) {
//     double v = 33.333;
//     cout << "gronk 2: double gronk(int n, float m)" << endl;
//     return v;
// }

// double cube(double x) {
//     return x;
// }
// double cube(double & x) {
//     return x;
// }

// double test(int x) {
//     return x;
// }
// double test(const int x) {
//     return x;
// }

int func(int a) {
    cout << "func version 1" << endl;
    return a;
}
double func(char b){
    double d = 2.0;
    cout << "func version 2" << endl;
    return d;
}


void staff (double & rs) {
    cout << "match staff (double & rs) " << endl;
}
void staff (const double & rs) {
    cout << "match staff (const double & rs) " << endl;
}
void staff (double && rs) { // && 右值引用
    cout << "match staff (double && rs) " << endl;
}