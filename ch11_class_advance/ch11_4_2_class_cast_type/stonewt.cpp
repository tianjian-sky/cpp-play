#include <iostream>
using std::cout;
#include "stonewt.h"

/**
* 关闭隐式转换
* explicit 关键字
*/

/**
* 2. 转换函数
* 将一个类的对象转换成一个类型数据
* a. 转换函数必须是类成员
* b. 转换函数不能指定返回类型
* c. 转换函数不能有参数
**/

/**
* 2. 转换函数 强制显式转换
* explicit 关键字 -std=c++11
**/


Stonewt::Stonewt(double lbs) {
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(long lbs) {
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs) {
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}
Stonewt::Stonewt() {
    stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt() {

}
Stonewt Stonewt::testReturnCast() {
    return pounds;
}
void Stonewt::show_lbs() const {
    cout << stone << " stone, " << pds_left << " pounds\n";
}
void Stonewt::show_stn() const {
    cout << pounds << " pounds\n";
}

// conversion functions
Stonewt::operator int() const {
    return int (pounds + 0.5);
}
Stonewt::operator double() const {
    return pounds;
}