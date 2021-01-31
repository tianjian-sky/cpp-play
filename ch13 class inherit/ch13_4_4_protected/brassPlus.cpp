#include <iostream>
#include "std.h"
#include "brass.h"
#include "brassPlus.h"

BrassPlus::BrassPlus(const std::string & s, long an, double bal, double ml, double r)
:Brass(s, an, bal) {
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) {
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const {
    format initialState = setFormat();
    precis prec = cout.precision(2);
    Brass::ViewAcct();
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate:" << 100 * rate << "%" << endl;
    restore(initialState, prec);
}

void BrassPlus::Withdraw(double amt) {
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = balance;
    if (amt <= bal) {
        Brass::Withdraw(amt);
    } else if (amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance*(1.0+rate);
        cout << "Bank advance:$" << advance << endl;
        cout << "Finance charge:$" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    } else {
        cout << "Credit limit exceeded. Transaction cancelled." << endl;
    }
    restore(initialState, prec);
}
