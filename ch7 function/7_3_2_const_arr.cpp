#include <iostream>
const int ARR_SIZE = 8;
int sum_arr(int arr[], int n);
using namespace std;
struct person {
    std::string name;
    float age;
};
int main () {
    const int c1 = 3;
    const int arr[ARR_SIZE] = {1,2,4,8,16,32,64,128};
    const person p1 = {
        "Alan",
        28
    };
    p1.name = "John";
    // cout << p1.name << endl; // error
    // c1=5; // invalid

    /**
    * const 数组不可改写
    */
    // arr[6] = 0; // invalid assignment of readonly location
}

/**
数组名和指针
多数情况下，数组名被解释为数组第一个元素的地址
    double wages[3];
    double *pw = wages;
    wages=&wages[0]
    wages[1] <--> *(wages+1)
区别：
1.数组名是常量，不能修改
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