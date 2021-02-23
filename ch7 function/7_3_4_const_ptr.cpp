#include <iostream>
const int ARR_SIZE = 8;
int sum_arr(int arr[], int n);
using namespace std;
int main () {
    const int c1 = 3;
    // c1=5; // invalid
    int value = 1;
    int * pt1 = &value;
    const int * pt2 = &value;
    
    *pt1 += 1;
    cout << "non const ptr change:" << *pt1 << endl; // CHANGED
    pt1 += 1;
    cout << "non const ptr loc change:" << *pt1 << endl; // CHANGED

    /**
    *1. 非const变量地址赋值给const指针， const指针不能修改
    */
    // *pt2 += 1;
    // cout << "const ptr change:" << *pt2 << endl; // ERROR assignment of readonly location
    // pt2 += 1;
    // cout << "const ptr location change:" << *pt2 << endl; // ERROR assignment of readonly location

    /**
    * 2.
    * const 变量地址可以赋值给const指针
    * const变量地址 不可以 赋值给常规指针
    */
    const int c = 3;
    const int * pc1 = &c;
    cout << "const var to const ptr:" << *pc1 << endl;
    //*pc1 += 1; // invalid
    pc1 += 1;
    cout << "const var to const ptr:" << *pc1 << endl;

    int * pNormal;
    pNormal = &c; // invalid
    cout << "var to const ptr:" << *pNormal << endl;
}

/**
* 因此尽量应该使用const指针 ！！
* 避免无意间修改数据 保护原数据，指针地址可随意修改
* 可以同时接收const或非const实参
*/


/**
数组名和指针
多数情况下，数组名被解释为数组第一个元素的地址
    double wages[3];
    double *pw = wages;
    wages=&wages[0]
    wages[1] <--> *(wages+1)
区别：
1.数组名是常量指针，不能修改
    wages = wages + 1; // invalid
    pw = pw + 1 // valid
2.对数组名运用sizeof，得到的是整个数组的长度，对指针用sizeof，得到的是指针的长度
    sizeof wages; // 24
    sizeof; pw // 4
*
/

/**
当且仅当在函数原型及函数头中，
int *arr 与 int arr[]含义相同，表示一个int指针
因此必须显示传递数组长度，sizeof数组参数永远得到的是单个数组元素的长度。
*/

int sum_arr(int arr[], int n) {
    int sum = 0;
    double doubleArr[ARR_SIZE] = {1,2,4,8,16,32,64,128};
    double * pt = doubleArr;
    cout << "sizeof arr parameter is" << sizeof arr << endl; // 8 
    cout << "sizeof arr name is" << sizeof doubleArr << endl; // 64 sizeof 数组名
    cout << "sizeof arr pointer is" << sizeof pt << endl; // 8
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}