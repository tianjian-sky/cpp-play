#ifndef STD_H_
#define STD_H_

#include <iostream>
using std:: cout;
using std::endl;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
format setFormat();
void restore(format f, precis p);


#endif