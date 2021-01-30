#ifndef BRASS_H_
#define BRASS_H_

#include "std.h"
#include <string>

class Brass
{
    private:
        std::string fullName;
        long acctNum; // 账号
        double balance;
    public:
        Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
        void Deposit(double amt);
        virtual void Withdraw(double amt);
        double Balance() const;
        virtual void ViewAcct () const;
        virtual ~Brass() {}
};

#endif