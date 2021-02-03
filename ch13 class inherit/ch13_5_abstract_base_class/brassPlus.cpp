#include <iostream>
#include "acctabc.h"
#include "brass.h"
#include "brassPlus.h"
using std::cout;
using std::ios_base;
using std::endl;
using std::string;


BrassPlus::BrassPlus(const std::string & s, long an, double bal, double ml, double r) : AcctABC(s, an, bal) {
    maxLoan = ml;
    rate = r;
    owesBank = 0;
}
BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : AcctABC(ba) {
    maxLoan = ml;
    rate = r;
    owesBank = 0;
}
void BrassPlus::Withdraw(double amt) {
    Formatting f = SetFormat();
    double bal = Balance();
    if (amt <= bal) {
        AcctABC::Withdraw(amt);
    } else if (amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance:$ " << advance << endl;
        cout << "Finance charge:$ " << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    } else {
        cout << "Credit limit exceeded. Transaction cancelled." << endl;
    }
    Restore(f);
}
void BrassPlus::ViewAcct() const {
    Formatting f = SetFormat();
    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Account Number:" << AcctNum() << endl;
    cout << "Balance:$" << Balance() << endl;
    cout << "Maximum loan:$" << maxLoan << endl;
    cout << "Owed to bank:$" << owesBank << endl;
    cout.precision(3);
    cout << "Loan rate: " << 100 * rate << "%" << endl;
    Restore(f);
}