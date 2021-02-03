#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>

class AcctABC {
    private:
        std::string fullName;
        long accNum;
        double balance;
    protected:
        struct Formatting {
            std::ios_base::fmtflags flag;
            std::streamsize pr;
        };
        const std::string & FullName() const {return fullName;}
        long AcctNum() const {return accNum;}
        Formatting SetFormat() const;
        void Restore (Formatting & f) const;
    public:
        AcctABC(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
        void Deposit(double amt);
        double Balance() const {return balance;}
        /*
        * 纯虚函数
        */
        virtual void ViewAcct() const = 0;
        virtual void Withdraw(double amt) = 0;
        virtual ~AcctABC() {}
};


#endif