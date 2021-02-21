#include <iostream>
#include "worker0.h"
#include <string>


int main () {
    /*
    * 名称支配：
    * 派生类中的名称，优于直接或间接祖先类中的名称
    */

    C c;
    c.getQ();

    D2 d2;
    d2.getQ();
    /*
    * 名称支配规则与访问规则无关，即使是基类的private的成员。
    */
    d2.getM();
    return 0;
}