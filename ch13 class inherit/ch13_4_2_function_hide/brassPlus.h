#ifndef BRASS_P_H_
#define BRASS_P_H_

#include "./brass.h"
#include <string>

class BrassPlus : public Brass
{
    private:
        double maxLoan;
        double rate;
        double owesBank;
    public:
        BrassPlus(const std::string & s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
        BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
        virtual ~BrassPlus() {
            std::cout << "sub descructor called:" << Brass::getName() << std::endl;
        }
        virtual void ViewAcct() const;
        virtual void Withdraw(double amt);
        void ResetMax(double m) { maxLoan = m; };
        void ResetRate(double r) { rate = r; };
        void ResetOwes() {owesBank = 0; };

        /*
        * 方法隐藏
        * 重载的基类的虚方法，导致子类想调用基类的虚方法，调用不到
        */
        virtual void printName(std::string suffix) { std:: cout << Brass::getName() << suffix << std::endl;};
};

#endif