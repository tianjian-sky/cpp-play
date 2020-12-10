#include <iostream>
#include <string>
using namespace std;

/**
*
* 函数重载：同名函数，参数列表不同，返回值相同！！
* 特征标： 参数列表，函数签名。
*
*/

void print(const char *str, int width);
void print(double d, int width);
void print(long l, int width);
void print(int i, int width);
void print(const char *str);

/*
* 名称相同，签名相同，返回值不同，视为不同函数
*/
long gronk(int n, float m);
double gronk(int n, float m);

/* 
* 2. 类型引用和类型本身看作用一个特征标
*/
double cube(double x);
double cube(double & x);

int main () {
    
    /**
    * 1. 不匹配任何函数签名，c++尝试使用类型转换进行强制匹配，若此时可能有多个可能的匹配结果，错误
    * 2. 多个相同的函数签名
    * 3. 匹配函数时，不区分const和非const
    */

    print ("Pancakes", 15);
    print ("Syrup");
    print(1999.0, 10);
    print(1999, 12);
    print(1999L, 15);

    /**
    * 1. 不匹配任何函数签名，c++尝试使用类型转换进行强制匹配
    * 若此时可能有多个可能的匹配结果，错误
    */
    unsigned int year = 3210;
    print(year, 6);


    





    return 0; 
}
