#ifndef BRASS_H_
#define BRASS_H_

#include <string>
#include <iostream>
class Brass
{
    private:
        std::string fullName;
        long acctNum; // 账号
    protected:
        double balance;
    public:
        Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
        void Deposit(double amt);
        virtual void Withdraw(double amt);
        double Balance() const;
        virtual void ViewAcct () const;
        virtual ~Brass() {
            std::cout << "parent descructor called:" << fullName << std::endl;
        }
        std::string getName () { return fullName; };
        void printName() { std:: cout << fullName << std::endl;};
        int normalOverwrite() {
            return 1;
        }
        virtual int specialOverwrite() {
            std::cout << "parent overwrite called..." << std::endl;
            return 1;
        }
        virtual Brass & covianceOverwrite () {
            std::cout << "parent coviance overwrite called..." << std::endl;
            return *this;
        }
};

#endif