#include <iostream>
#include "./namesp.h"

/**
 * 命名空间是开放的，即可以随时把新的成员名称加入到已有的命名空间之中去。
*/

namespace pers {
    using std::cout;
    using std::cin;

    void getPerson(Person &rp) {
        cout << "Enter first name: ";
        cin >> rp.fname;
        cout << "Enter last name: ";
        cin >> rp.lname;
    }

    void showPerson(const Person &rp) {
        std::cout << rp.lname << ", " << rp.fname;
    }
}

namespace debts {
    void getDebt(Debt &rd) {
        getPerson(rd.name);
        std::cout << "Enter debt: ";
        std::cin >> rd.amount;
    }
    void showDebt(const Debt &rd) {
        showPerson(rd.name);
        std::cout << ": $" << rd.amount << std::endl;
    }
    double sumDebts(const Debt ar[], int n) {
        double total = 0;
        for (int i = 0; i < n; i++) {
            total += ar[i].amount;
        }
        return total;
    }
}