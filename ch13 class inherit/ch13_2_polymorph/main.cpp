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


    /*
   * 公有派生：
   * 基类的公有成员成为派生类的公有成员
   * 基类的私有成员也成为派生类的一部分，但是只能通过基类的公有和保护方法访问
   */
   
    /*
    * 构造方法链：
    * 如果不调用父类的构造函数进行初始化，则会自动调用父类的默认构造函数
    * 最好显示地调用正确的构造函数
    */

    /*
    * 子类不可直接访问父类的private成员。（等同于java的private）
    */

    cout << "create TableTennisPlayer player1(\"Tara\", \"Boomdea\", false);" << endl;
    TableTennisPlayer player1("Tara", "Boomdea", false);
    cout << "create GoodPlayer gp1(1140, \"Mallory\", \"Duck\", true);" << endl;
    GoodPlayer gp1(1140, "Mallory", "Duck", true);
    cout << "create GoodPlayer gp2;" << endl;
    GoodPlayer gp2;


    /*
    * 参数初始化表也可以是类的构造函数
    */
    /*
    * 通过参数初始化表初始化父类实例的时候，将视具体情况调用复制构造函数
    * 
    * GoodPlayer::GoodPlayer(unsigned int r, const TableTennisPlayer & tp)
    *  : TableTennisPlayer(tp), rating(r){
    * }
    * 注：此处参数初始化表传入的是一个类实例的值
    */
    
    cout << "create gp3(1233, player1)" << endl;
    GoodPlayer gp3(1233, player1);

    player1.Name();
    gp1.Name();
    gp2.Name();

    /*
    * 实例销毁的时候先调用子类的析构函数，再调用父类的析构函数
    */

    
    /*
    * 父类指针指向子类对象
    * 不可以逆向操作
    */
    cout << "TableTennisPlayer *tpp;" << endl;
    TableTennisPlayer *tpp; // 指针变量声明不调用构造函数
    tpp = &gp1;
    tpp->Name();
    // tpp->Rating(); // 数据保护，父类指针指向子类对象，只能调用父类的成员方法

    /*
    * 父类引用指向子类对象
    * 不可以逆向操作
    * 用途：
    * 复制构造函数，复制运算符，使得参数接受引用类型的地方既可以接受父类也可以接受子类
    */
    TableTennisPlayer & tpr = gp2;
    tpr.Name();
    // tpr.Rating(); // 数据保护，父类引用指向子类对象，只能调用父类的成员方法

    return 0;
}