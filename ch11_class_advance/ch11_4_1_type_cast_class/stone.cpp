#include <iostream>
using std::cout;
#include "stonewt.h"
void display(const Stonewt &st, int n);


int main () {

    /**
     * 1.转换构造函数：
     * 将其它类型转换为当前类的类型
     * 构造函数只能有一个参数
     * 如果有二义性，则放弃尝试 (不能有多个匹配的转换函数)
     * 
    */
   /**
    * 1.1 转换构造函数 隐式转换使用场景
    * 
    * Stonewt Jumbo(7000);
    * Jumbo = 7300;
    * 
    * a）Stonewt对象初始化为double值
    * b）double赋给Stonewt对象
    * c）double值传递给接受Stonewt参数的函数时
    * d）返回值被声明为Stonewt的函数试图返回dboule值时
    * e）上述任何情况下，使用可转换为double类型的内置函数时
    * /

   /**
    * 1.2 关闭隐式转换
    * explicit 关键字
    */
   /**
    * 当关闭隐式转换时出现如下报错信息：
    * 这也就说明 = 操作符被重载了
    * .\stonewt.h:4:7: note: candidate: Stonewt& Stonewt::operator=(const Stonewt&)
    * class Stonewt {
    *   ^
    *.\stonewt.h:4:7: note:   no known conversion for argument 1 from 'double' to 'const Stonewt&'
    **/

   /**
    * 2. 类型转换函数
    * 将一个类的对象转换成一个类型数据
    * 
    **/


    // 使用构造函数来进行隐式转换
    // Stonewt incognito = 275;
    Stonewt incognito = (Stonewt) (double)275; // 如果有二义性，则放弃尝试 (不能有多个匹配的转换函数)
    Stonewt wolfe((double)285.7); // 隐式转换场景 e）上述任何情况下，使用可转换为double类型的内置函数时
    Stonewt taft((double)21, 8);

    cout << "The celebrity weighed ";
    incognito.show_stn();
    cout << "The detective weighed ";
    wolfe.show_stn();
    cout << "The prisident weighed ";
    taft.show_lbs();

    // 使用构造函数来进行隐式转换
    incognito = (Stonewt) 276.8;
    taft = (Stonewt) (double)325;
    cout << "After dinner, the celebrity weighted ";
    incognito.show_stn();
    cout << "After dinner, the prisident weighted ";
    taft.show_lbs();
    display(taft, 2);
    cout << "The wrestler weighted even more." << std::endl;
    /**
     *  a.如果有二义性，则放弃尝试 (不能有多个匹配的转换函数)
     *  b. 连续强制转换
     */
    display((Stonewt) (double)422, 2);
    cout << "No stone left unearned." << std::endl;

    // 隐式转换场景 d）返回值被声明为Stonewt的函数试图返回dboule值时
    wolfe.testReturnCast();

    return 0;
}

void display(const Stonewt &st, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Wow! ";
        st.show_stn();
    }
}
