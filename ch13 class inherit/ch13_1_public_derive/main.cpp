#include <iostream>
#include "tbPlayer.h"
#include "goodPlayer.h"

int main (void) {
    using std::cout;
    using std::endl;

    /**
    * C++构造函数初始化列表
    * http://c.biancheng.net/view/2223.html
    *
    * 使用构造函数初始化列表并没有效率上的优势，仅仅是书写方便，尤其是成员变量较多时，这种写法非常简单明了
    * 使用构造函数初始化列表,成员变量的初始化顺序与初始化列表中列出的变量的顺序无关，它只与成员变量在类中声明的顺序有关
        * 如:
            {...
                private:
                    int m_a;
                    int m_b;
            ...
            }
        *   Demo::Demo(int b): m_b(b), m_a(m_b){ } 
        * 等价于
        *   Demo::Demo(int b): m_b(b), m_a(m_b){
                m_a = m_b;
                m_b = b;
            }
    * 构造函数初始化列表还有一个很重要的作用，那就是初始化 const 成员变量

    */


    TableTennisPlayer player1("Tara", "Boomdea", false);
    GoodPlayer gp1(1140, "Mallory", "Duck", true);
    player1.Name();
    gp1.Name();
    return 0;
}