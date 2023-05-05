#include <iostream>
#include <cmath>
#include <string>
#include "a.h"

using namespace std;
/*
    栈展开
        函数出现异常，程序释放栈（当前函数内存和局部对象），直到第一个try块的返回地址，然后控制权转到try块后的异常处理，而不是返回地址后的第一条语句。

    对new 动态分配的内存，栈展开期间不会释放资源。
    析构函数从不应该抛出异常
    构造期间剖出异常，此时对象可能只是部分被构造，需要保证能撤销这些已构造成员
    未捕获的异常会终止程序

    auto_ptr能在栈栈开时释放

*/
class Demo {
    private:
        string word;
    public:
        Demo (const string & str) {
            word = str;
            cout << "demo " << word << " created" << endl;
        }
        ~Demo () {
            cout << "demo " << word << " destroyed" << endl;
        }
        void show () const {
            cout << "demo " << word << " lives!" << endl;
        }
};

double hmean (double a, double b);
double gmean (double a, double b);
double means (double a, double b);

int main () {
    double x, y, z;
    {
        Demo d1("found in block main");
        cout << "Enter two nums: ";
        while (cin >> x >> y) {
            try {
                z = means(x, y);
                cout << "mean of " << x << " and " << y << " is " << z << endl;
                cout << "Enter next pair:";
            } catch (bad_hmean &bg) {
                bg.mesg();
                cout << "Try again" << endl;
                continue;
            } catch (bad_gmean &hg) {
                cout << hg.mesg();
                // cout << "Value used: " << hg.v1 << ", " << hg.v2 << endl;
                cout << "Sorry, end" << endl;
                break;
            }
            d1.show();
            cout << "Bye!" << endl;
            cin.get();
            cin.get();
            return 0;
        }
    }
}

double hmean (double a, double b) {
    if (a == -b) {
        throw bad_hmean(a, b);
    }
    return 2.0 * a * b / (a + b);
}
double gmean (double a, double b) {
    if (a < 0 || b < 0) {
        throw bad_gmean(a, b);
    }
    return sqrt(a * b);
}
double means (double a, double b) {
    double am, hm, gm;
    Demo d2 ("found in means()");
    am = (a + b) / 2.0;
    try {
        hm = hmean(a, b);
        gm = gmean(a, b);
    } catch (bad_hmean & bg) {
        bg.mesg();
        cout << "caught in means" << endl;
        throw;
    }
    d2.show();
    return (am + hm + gm) / 3.0;
}