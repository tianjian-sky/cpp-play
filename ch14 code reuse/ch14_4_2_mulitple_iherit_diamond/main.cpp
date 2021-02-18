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

    std::cout << "Test diamond inherit:" << std::endl;

    /*
    *
    * Singer, Waiter都继承自Worker，
    * S_W 同时继承了Singer，Waiter，因此S_W的实例将保护两个Worker组件
    * 
    */

    Singer_Waiter sw = Singer_Waiter();

    /*
    * 如果将混合子类对象的地址赋值给基类的指针，将出现二义性错误。
    * 因为钻石继承的情况下，子类包含两个基类的对象，有两个可能的地址，不知道该选择哪个地址
    */

    //Worker *w = &sw; // error: 'Worker' is an ambiguous base of 'Singer_Waiter'

    /*
    * 这种情况下，可以使用强制类型转换，明确要指向子类中从那条路径继承来的共有基类对象
    */

    Worker *w1 = (Waiter *) &sw;
    Worker *w2 = (Singer *) &sw;
    return 0;
}