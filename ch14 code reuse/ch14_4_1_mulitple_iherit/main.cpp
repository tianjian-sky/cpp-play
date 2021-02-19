#include <iostream>
#include "worker0.h"

const int LIM = 4;


/**
* 指针数组与数组指针
* A) int *p1[10];
* B) int (*p2)[10];
*A: “[]”的优先级比“*”要高。p1 先与“[]”结合，构成一个数组的定义，数组名为p1，int *修饰的是数组的内容，即数组的每个元素。那现在我们清楚，这是一个数组，其包含10 个指向int 类型数据的指针，即指针数组。
*B:  至于p2 就更好理解了，在这里“（）”的优先级比“[]”高，“*”号和p2 构成一个指针的定义，指针变量名为p2，int 修饰的是数组的内容，即数组的每个元素。数组在这里并没有名字，是个匿名数组。
*/

int main () {
    Waiter bob("Bob Apple", 314L, 5);
    Singer bev("Bevely Hills", 522L, 3);
    Waiter w_temp;
    Waiter s_temp;
    Worker *pw[LIM] = {&bob, &bev, &w_temp, &s_temp}; // Worker *temp = pw[0] = &bob (*Waiter)

    int i;
    for (i = 2; i < LIM; i++) {
        pw[i] -> Set();
    }
    for (i = 0; i < LIM; i++) {
        pw[i] -> Show();
        std::cout << std::endl;
    }
    return 0;
}