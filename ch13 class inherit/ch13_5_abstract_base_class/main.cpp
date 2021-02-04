#include <iostream>
#include "acctabc.h"
#include "brassPlus.h"
#include "string"

const int CLIENTS = 4;

int main () {
    using std::cin;
    using std::cout;
    using std::endl;

    /**
    * 指针数组与数组指针
    * A) int *p1[10];
    * B) int (*p2)[10];
    *A: “[]”的优先级比“*”要高。p1 先与“[]”结合，构成一个数组的定义，数组名为p1，int *修饰的是数组的内容，即数组的每个元素。那现在我们清楚，这是一个数组，其包含10 个指向int 类型数据的指针，即指针数组。
    *B:  至于p2 就更好理解了，在这里“（）”的优先级比“[]”高，“*”号和p2 构成一个指针的定义，指针变量名为p2，int 修饰的是数组的内容，即数组的每个元素。数组在这里并没有名字，是个匿名数组。
    */
    AcctABC * p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    AcctABC abc("John Doe", 33333, 9999);

    /*
    * 纯虚函数
    */

    for (int i = 0; i < CLIENTS; i++) {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or 2 for BrassPlus account: ";
        while(cin >> kind && (kind != '1' && kind != '2')) {
            cout << "Enter either 1 or 2: " ;
        }
        if (kind == '1') {
            p_clients[i] = new Brass(temp, tempnum,tempbal);
        } else {
            double tmax, trate;
            cout << "Enter the overdraft limit:$";
            cin >> tmax;
            cout << "Enter the interest rate " << "as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        } 
        while(cin.get() != '\n') {
            continue;
        }
    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++) {
        p_clients[i]->ViewAcct();
        cout << endl;
    }
    for (int i = 0; i < CLIENTS; i++) {
        delete p_clients[i];
    }
    cout << "Done." << endl;
    return 0;
}