#include <iostream>
using std::cout;
#include "stonewt.h"

/**
* 关闭隐式转换
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

Stonewt::Stonewt(double lbs) {
    cout << "constructor called Stonewt(double lbs)" << std::endl;
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(long lbs) {
    cout << "constructor called Stonewt(long lbs)" << std::endl;
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs) {
    cout << "constructor called Stonewt(int stn, double lbs)" << std::endl;
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}
Stonewt::Stonewt() {
    cout << "constructor called Stonewt()" << std::endl;
    stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt() {
    cout << "descructor called ~Stonewt()::" << pounds << std::endl;
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
