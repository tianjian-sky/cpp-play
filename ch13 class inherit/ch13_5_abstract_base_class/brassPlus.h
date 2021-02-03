#ifndef BRASSPLUS_H_
#define BRASSPLUS_H_
#include <iostream>
#include "./acctabc.h"
#include "./brass.h"

class BrassPlus : public AcctABC {
    private:
        double maxLoan;
        double rate;
        double owesBank;
    public:
        BrassPlus(const std::string & s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.1);
        BrassPlus(const Brass & ba, double ml = 500, double r = 0.1);
        virtual void Withdraw(double amt);
        virtual void ViewAcct() const;
        void ResetMax (double m) {maxLoan = m;}
        void ResetRate(double r) {rate = r;}
        void ResetOwes () {owesBank = 0;}
};


#endif