#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"
using std::cin;
using std::cout;
using std::endl;

int main () {
    Stack<std::string> st;
    char ch;
    std::string po;
    cout << "Please enter A to add a order." << endl;
    cout << "P to process a order, or Q to quit." << endl;
    /*
    * 模板不是函数，不能单独编译，所有模板信息需放在一个头文件中
    */

    /*
    * 模板是编译指令
    */
    while(cin >> ch && std::toupper(ch) != 'Q') {
        while (cin.get() != '\n') {
            continue;
        }
        if (!std::isalpha(ch)) {
            cout << "\a";
            continue;
        }
        switch(ch) {
            case 'A':
            case 'a':
                cout << "Enter a order number to add: ";
                cin >> po;
                if (st.isFull()) {
                    cout << "Stack already full!" << endl;
                } else {
                    st.push(po);
                }
                break;
            case 'P':
            case 'p':
                if (st.isEmpty()) {
                    cout << "Stack already empty!" << endl;
                } else {
                    st.pop(po);
                    cout << "Order #" << po << " popped." << endl;
                    break;
                }
        }
        cout << "Please enter A to add a purchase order." << endl;
        cout << "P to process an order, or Q to quit." << endl;
    }
    cout << "Bye!" << endl;
    return 0;
}