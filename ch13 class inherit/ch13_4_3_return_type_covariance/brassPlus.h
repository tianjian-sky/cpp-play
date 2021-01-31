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
        void printName(std::string suffix) { std:: cout << Brass::getName() << suffix << std::endl;};

        /*
        * 虚函数覆盖
        */
        std::string normalOverwrite(std::string s) {
            return 2 + "change" + s;
        }
        // 返回类型与重写虚拟函数 "Brass::specialOverwrite" 的返回类型 "int" 既不相同，也不协变
        // virtual char specialOverwrite() {
        //     return 's';
        // }
        // double specialOverwrite() {
        //     return 3d;
        // }
        virtual int specialOverwrite(int b) {
            std::cout << "child overwrite called..." << std::endl;
            return 2 + b;
        }

        virtual BrassPlus & covianceOverwrite (int a) {
            std::cout << "sub coviance overwrite called..." << std::endl;
            return *this;
        }
};

#endif