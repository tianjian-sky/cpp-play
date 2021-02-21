#include <iostream>
#include "worker0.h"
#include <string>

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


    Singer_Waiter_Mix sw("Bob Apple", 314L, 3, 5); // 不同于一般的继承，虚基类的构造函数至多只会调用一次

    bob.Show();
    bev.Show();
    sw.Show();

    /*
    * 当类通过多条虚途径和非虚途径继承某个特定的基类时，该类将包含一个包含所有的虚途径的基类对象，和分别表示各条非虚途径的基类对象
    */

    /*
    * 同时继承了虚基类和非虚基类，因此此时包含1个从虚继承的对象和多个非虚继承的对象，因此下面的写法就报基类不明确了
    */
    // Worker *w1 = &sw; // error: 'Worker' is an ambiguous base of 'Singer_Waiter_Mix'

    Worker *w1 = (Singer *)&sw; // 指向虚继承的
    Worker *w2 = (Waiter *)&sw; // 指向虚继承的
    Worker *w3 = (Singer2 *)&sw; // 指向非虚继承的
    Worker *w4 = (Waiter2 *)&sw; // 指向非虚继承的
    return 0;
}