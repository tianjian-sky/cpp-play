#include <iostream>
#include "stock00.h"

/**
* 构造函数：
* 构造函数没有返回类型
* 没有定义任何构造函数时，程序会提供默认构造函数
* 提供了构造函数时，程序员必须提供默认构造函数
* 1）给已经有的构造函数的所有参数提供默认参数
* 2）通过函数重载定义一个没有参数的构造函数
*/


/**
 * c++ 类对象初始化
 * 1.复制初始化（int a = 5;）
 * 2.直接初始化（int a(5);） 
    * A x(2);　　//直接初始化，调用构造函数
    * A y = x;　　//复制初始化，调用复制构造函数
 * 
 * ClassName xxx; 这样其实已经初始化了！！，调用默认的无参构造函数
 */


int main () {
    /**
    * ClassName xxx; 这样其实已经初始化了！！，调用默认的无参构造函数
    */
    Stock fluffy_the_cat;
    fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(300000, 40.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(300000, 0.125);
    fluffy_the_cat.show();
    return 0;
}