#include "studentc.h"
#include <string>

using std::ostream;
using std::endl;
using std::istream;
using std::string;

/*
* 私有继承，访问父类的方法
* 此处因为继承来的对象没有名称，
* 使用xxx::xxx()调用包含的对象的公有方法
*/
double Student::Average() {
    if (ArrayDb::size() > 0) {
        return ArrayDb::sum() / ArrayDb::size();
    } else {
        return 0;
    }
}

/*
* 私有继承，访问子对象
* 因为继承来的对象没有名称，
* 所以通过强制转型，访问
*/

// const string & == string const &
const std::string & Student::Name() const {
    return (const string &) * this;
}
double & Student::operator[](int i) {
    return ArrayDb::operator[](i);
}
double Student::operator[] (int i) const {
    return ArrayDb::operator[](i);
}

/*
* 私有继承，访问子对象的友元函数
* 通过强制转型，访问
*/

std::istream & operator >>(std::istream & is, Student & stu) {
    is >> (string &) stu;
    return is;
}
std::istream & getline(std::istream & is, Student & stu) {
    getline(is, (string &) stu);
    return is;
}
std::ostream & operator <<(std::ostream & os, const Student & stu) {
    os << (string &) stu;
    return os;
}