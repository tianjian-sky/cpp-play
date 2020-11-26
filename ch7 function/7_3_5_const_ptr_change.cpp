#include <iostream>
const int ARR_SIZE = 8;
using namespace std;
int main () {
   
    int val = 1;
    const int cVal = 3;

    const int * cp1 = &val;
    const int * cp2 = &cVal;

    int * const cpp1 = &val;
    int val2 = 2;
    // int * const cpp2 = &cVal;  error: invalid conversion from 'const int*' to 'int*  非const的指针不能指向const 变量

    const int * const ppp = &val;

    cout << "*cp1:" << *cp1 << endl;
    cout << "*cp2:" << *cp2 << endl;

    cout << "*cpp1:" << *cpp1 << endl;

    cout << "*ppp:" << *ppp << endl;

    /**
    * const int *pt
    * const (int * pt) const 修饰 *a，不能改，a能改 （pt）是一个指针
    * int * const pt
    * int * const (pt) const 修饰pt，pt不能改，*pt能改 （pt）是一个指针
    */
    /**
    * const只是限定某个地址存储的内容不可修改
    * const 属于修饰符 ，关键是看const 修饰的位置在那里
    *
    *
    * const int *pt
    * const (int * pt) const 修饰 *a，不能改，a能改 （pt）是一个指针
    * int * const pt
    * int * const (pt) const 修饰pt，pt不能改，*pt能改 （pt）是一个指针
    * const int * const pt
    * pt,*pt 都不能修改
    *
    */

    // cp1 += 1;
    // *cp1 += 1; // error: assignment of read-only location;

    // cp2 += 1;
    // *cp2 += 1; // error: assignment of read-only location;

    // cout << "*cp1:" << *cp1 << endl;
    // cout << "*cp2:" << *cp2 << endl;


    cout << "*cpp1:" << *cpp1 << endl;

    // cpp1 += 1; // error: assignment of read-only variable 'cpp1'
    // *cpp1 += 1; // error: invalid conversion from 'const int*' to 'int*
    *cpp1 = val2;
    cout << "*cpp1:" << *cpp1 << endl;

    // ppp += 1; // error: assignment of read-only variable 'ppp'
    *ppp += 1; // error: assignment of read-only location '*(const int*)ppp'
}
