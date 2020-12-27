#include <iostream>
#include "./mytime1.h"

/**
 * 操作符重载
 * 1)将操作符重载实现为类的成员函数
 * 2)操作符重载实现为非类的成员函数（即全局函数）
 */

/**
 * 操作符重载
 * a.必须至少有一个操作数是用户自定义类型，防止用户为标准类型重载运算符。标准类型不可重载
 * b.不能违反运算符原来的句法规则。
 * c. 不能创建新的运算符
 * d. 有些操作符不能重载(sizeof,.,:,::,*,.,typeid, const_cast,dynamic_cast,reinterpret_cast,static_cast)
 * e.有些操作符只能通过类的成员函数进行重载
 */

int main() {
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;
    Time diff;
    Time adjusted;

    cout << "Planning time = " << endl;
    planning.Show();
    cout << endl;

    cout << "coding time = " << endl;
    coding.Show();
    cout << endl;

    cout << "fixing time = " << endl;
    fixing.Show();
    cout << endl;

    total = coding + fixing;
    cout << "coding+fixing time = " << endl;
    total.Show();
    cout << endl;

    diff = coding - fixing;
    cout << "coding - fixing time = " << endl;
    diff.Show();
    cout << endl;

    Time morefixing(3,29);
    cout << "morefixing time = " << endl;
    morefixing.Show();
    cout << endl;

    total = morefixing.operator+(total);
    cout << "morefixing.operator+(total) time = " << endl;
    total.Show();
    cout << endl;

    adjusted = total * 1.5;
    cout << "adjusted work time = ";
    adjusted.Show();
    cout << endl;
    
    return 0;
}