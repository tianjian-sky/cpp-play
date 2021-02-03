#include <iostream>
#include "acctabc.h"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;


AcctABC::AcctABC(const std::string & s, long an, double bal) {
    fullName = s;
    accNum = an;
    balance = bal;
}
AcctABC::Formatting AcctABC::SetFormat() const {
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}
void AcctABC::Restore (Formatting & f) const {
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}
void AcctABC::Deposit(double amt) {
    if (amt < 0) {
        cout << "Negative deposit not allowed; " << "deposit is cancelled." << endl;
    } else {
        balance += amt;
    }
}
/*
* 纯虚函数
*/
void AcctABC::Withdraw(double amt) {
    balance -= amt;
}
