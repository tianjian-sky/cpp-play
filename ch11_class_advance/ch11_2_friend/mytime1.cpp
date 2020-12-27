#include <iostream>
#include "./mytime1.h"

Time::Time() {
    hours = minutes = 0;
}
Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}
void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}
void Time::AddHr(int h) {
    hours += h;
}
void Time::Reset(int h, int m) { // ① 有函数声明(原型)时,默认参数可以放在函数声明或者定义中，但只能放在二者之一
    hours = h;
    minutes = m;
}
/**
 * 操作符重载
 * 1)将操作符重载实现为类的成员函数
 */
Time Time::operator+(const Time &t) const {
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}
Time Time::operator-(const Time &t) const {
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes + 60 * hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}
Time Time::operator*(double mult) const {
    Time result;
    long total = hours*mult*60 + minutes*mult;
    result.hours = total / 60;
    result.minutes = total % 60;
    return result;
}
Time operator*(double mult, const Time & t) {
    Time result;
    long total = t.hours*mult*60 + t.minutes*mult;
    result.hours = total / 60;
    result.minutes = total % 60;
    return result;
}
void Time::Show() const {
    std::cout << hours << " hours, " << minutes << " minutes" << std::endl;
}