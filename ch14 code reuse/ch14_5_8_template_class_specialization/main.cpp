#include "stacktp.h"


/*
* 模板类的实例化，具体化
* 实例化：
*   隐式实例化
*   显式实例化：编译器先生成一个类声明（包含方法定义）
*
*   具体化：
*   针对某个类型生成一个特殊的模板
*   部分具体化：
*   一部分参数具体化
*/
int main() {
    Person<int> p;
    p.Say(1);
    Person<char *>p2;
    p2.Say("good");
    Car<int, double> c1;
    c1.Say(9, 11);
    Car <int, char *> c2;
    c2.Say(100, "Benz");
    return 0;
}