#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"
using std::cin;
using std::cout;
using std::endl;

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
        sizeof; pw // 8
    当且仅当在函数原型及函数头中，
    int *arr 与 int arr[]含义相同，表示一个int指针
    因此必须显示传递数组长度，sizeof数组参数永远得到的是单个数组元素指针的长度。
*/

/*
* 'sizeof' on array function parameter 'arr' will return size of 'int*'
*/
void sum_arr(int *p, int arr[]) {
    cout << "sizeof p:" << sizeof p << endl; // 这里sizeof的是指针，而不是指针指向的内容！！
    cout << "sizeof arr:" << sizeof arr << endl;
    cout << "sizeof *p:" << sizeof *p << endl;
    cout << "sizeof *arr:" << sizeof *arr << endl;
    cout << "sizeof arr[0]:" << sizeof arr[0] << endl;
}

int main () {
    Stack<char *> st;
    char ch;
    char po[40];
    int b = 1;
    int *pw1 = &b;
    int arr[4] = {0, 1, 2, 3};
    int *pw2 = arr;
    cout << sizeof b << endl; 
    cout << sizeof pw1 << endl; 
    cout << sizeof pw2 << endl; // sizeof 数组名的指针，得到第一个元素指针的大小
    cout << sizeof arr << endl; // sizeof 数组名，得到整个数组的的大小
    sum_arr(arr, arr);
    cout << "Please enter A to add a order." << endl;
    cout << "P to process a order, or Q to quit." << endl;

    return 0;
    /*
    * 模板不是函数，不能单独编译，所有模板信息需放在一个头文件中
    */

    /*
    * 模板是编译指令
    */
    while(cin >> ch && std::toupper(ch) != 'Q') {
        while (cin.get() != '\n') {
            continue;
        }
        if (!std::isalpha(ch)) {
            cout << "\a";
            continue;
        }
        switch(ch) {
            case 'A':
            case 'a':
                cout << "Enter a order number to add: ";
                cin >> po;
                if (st.isFull()) {
                    cout << "Stack already full!" << endl;
                } else {
                    st.push(po);
                }
                break;
            case 'P':
            case 'p':
                if (st.isEmpty()) {
                    cout << "Stack already empty!" << endl;
                } else {
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
                    */

                    /**
                        当且仅当在函数原型及函数头中，
                        int *arr 与 int arr[]含义相同，表示一个int指针
                        因此必须显示传递数组长度，sizeof数组参数永远得到的是单个数组元素指针的长度。
                    */

                    /*
                    * error1: 引用变量必须引用某种类型的左值，而不是数组名
                    * error2：数组名不可修改
                    */
                    
                    st.pop(po); // 数组名是常量指针
                    cout << "Order #" << po << " popped." << endl;
                    break;
                }
        }
        cout << "Please enter A to add a purchase order." << endl;
        cout << "P to process an order, or Q to quit." << endl;
    }
    cout << "Bye!" << endl;
    return 0;
}