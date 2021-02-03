#ifndef BRASS_H_
#define BRASS_H_
#include <iostream>
#include "./acctabc.h"

class Brass : public AcctABC {
    public:
        Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0) : AcctABC(s, an, bal) {
        }
        virtual void Withdraw(double amt);
        virtual void ViewAcct() const;
        virtual ~Brass() {}
};


#endif