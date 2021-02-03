#include <iostream>
#include "acctabc.h"
#include "brass.h"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;

void Brass::Withdraw(double amt) {
    if (amt < 0) {
        cout << "Withdrawal amount must be positive;" << "withdrawal canceled." << endl; 
    } else if (amt <= Balance()) {
        AcctABC::Withdraw(amt);
    } else {
        cout << "Withdrawal amount of $" << amt << " exceeds your balance." << endl << "Withdrawal canceled." << endl;
    }
}
void Brass::ViewAcct() const {
    Formatting f = SetFormat();
    cout << "Brass Client: " << FullName() << endl;
    cout << "Account Number:" << AcctNum() << endl;
    cout << "Balance:$" << Balance() << endl;
}
