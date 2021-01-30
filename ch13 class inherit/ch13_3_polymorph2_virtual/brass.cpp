#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

Brass::Brass(const std::string & s, long an, double bal) {
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt) {
    if (amt < 0) {
        cout << "Negative deposit not allowed; deposit is cancelled." << endl;
    } else {
        balance += amt;
    }
}

void Brass::Withdraw(double amt) {
    format initialState = setFormat();
    precis prec = cout.precision(2);
    if (amt < 0) {
        cout << "Withdrawal amount must be positive; withdrawal canceled." << endl;
    } else if (amt <= balance) {
        balance -= amt;
    } else {
        cout << "Withdrawal amount of $" << amt << " exceeds your balance. Withdrawal canceled." << endl;
    }
    restore(initialState, prec);
}

double Brass::Balance() const {
    return balance;
}

void Brass::ViewAcct () const {
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "ClientL " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState, prec);
}
