#ifndef STD_H_
#define STD_H_

#include <iostream>
using std:: cout;
using std::endl;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

format setFormat() {
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p) {
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}

#endif