#include <iostream>
using std::cout;
#include "stonewt.h"
void display(const Stonewt &st, int n);


int main () {

   /**
    * 2. 转换函数
    * 将一个类的对象转换成一个类型数据
    * a. 转换函数必须是类成员
    * b. 转换函数不能指定返回类型
    * c. 转换函数不能有参数
    **/

   /**
    * 转换函数 强制显式转换
    * explicit 关键字 -std=c++11
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

    /*
    * 转换函数
    */

    Stonewt poppins (9, 2.8);
    double p_wt = (double) poppins;
    int p_i_wt = (int) poppins;

    cout << "Convert to double =>" << std::endl;
    cout << "Poppins:" << p_wt << " pounds." << std::endl;
    cout << "Convert to int =>" << std::endl;
    cout << "Poppins:" << p_i_wt << " pounds." << std::endl;
    return 0;
}

void display(const Stonewt &st, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Wow! ";
        st.show_stn();
    }
}
