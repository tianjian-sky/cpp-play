#include "studentc.h"
#include <string>

using std::ostream;
using std::endl;
using std::istream;
using std::string;

double Student::Average() {
    if (scores.size() > 0) {
        return scores.sum() / scores.size();
    } else {
        return 0;
    }
}
const std::string & Student::Name() const {
    return name;
}
double & Student::operator[](int i) {
    return scores[i];
}
double Student::operator[] (int i) const {
    return scores[i];
}

std::istream & operator >>(std::istream & is, Student & stu) {
    is >> stu.name;
    return is;
}
std::istream & getline(std::istream & is, Student & stu) {
    getline(is, stu.name);
    return is;
}
std::ostream & operator <<(std::ostream & os, const Student & stu) {
    os << "Scores for " << stu.name << ":\n";
    stu.arr_out(os);
    return os;
}

// private method
std::ostream & Student::arr_out(std::ostream &os) const {
    int i;
    int lim = scores.size();
    if (lim > 0) {
        for (i = 0; i < lim; i++) {
            os << scores[i] << " ";
            if (i % 5 == 4) {
                os << endl;
            }
            if (i % 5 != 0) {
                os << endl;
            }
        }
    } else {
        os << "empty array" << endl;
    }
    return os;
}