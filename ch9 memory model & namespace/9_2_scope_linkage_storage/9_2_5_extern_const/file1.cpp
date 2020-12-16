#include <iostream>
#include "./coordin.h"

using namespace std;


/**
 * const 全局变量的链接性是内部的。
 * 这样做是为了方便在头文件中定义const 变量，以后在各个文件中引入头文件时，
 * 不会因为违反ODL原则而报错。因为此时他们都是内部链接性的，不存在重复定义。
 * 
 * 如果需要让const全局变量变成外部链接性的，则需要在其定义前面加extern
 * 
*/

const int const_global = 888;
extern const int extern_const_global = 999;

void readConst();

int main () {
   readConst();

   return 0;
}