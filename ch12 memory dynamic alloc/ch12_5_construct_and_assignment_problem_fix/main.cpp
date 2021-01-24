#include <iostream>
#include "stringnew.h"

const int ArSize = 10;
const int MaxLen = 81;

int main () {
    using std::cout;
    using std::cin;
    using std::endl;

    String name;
    cout << "Hi, what's your name?" << endl;
    cin >> name;
    cout << name << ", please enter up to " << ArSize << " short saying <empty line to quit>:" << endl;
    String sayings[ArSize]; // 数组初始化同时，各个数组元素初始化，调用无参构造函数
    char temp[MaxLen];
    int i;
    for (i=0; i<ArSize; i++) {
        cout << i+1 << ": ";
        cin.get(temp, MaxLen);
        while(cin && cin.get() != '\n') continue;
        if (!cin || temp[0] == '\0') {
            break;
        } else {
            sayings[i] = temp;
        }
    }
    int total = i;
    if (total > 0) {
        cout << "Here are your sayings:" << endl;
        for (i=0; i < total; i++) {
            cout << sayings[i][0] << ": " << sayings[i] << endl;
        }
        int shortest = 0;
        int first = 0;
        for (i=1; i < total; i++) {
            if (sayings[i].length() < sayings[shortest].length()) {
                shortest = i;
            }
            if (sayings[i] < sayings[first]) {
                first = i;
            }
        }
        cout << "Shortest saying:\n" << sayings[shortest] << endl;
        cout << "First alphabetically:\n" << sayings[first] << endl;
        cout << "This program used " << String::HowMany() << " String objects. Bye." << endl;

        cout << "test const" << endl;
        const String strConst("abc");
        cout << strConst[1] << endl;


    } else {
        cout << "No input! Bye." << endl;
    }

    /*
    * new 与delete 需配对使用
    */
    /*
    * 但是由于析构函数是没有参数的,那么从而无法通过参数的不同来达到重载多个析构函数的目的,从而析构函数只能有一个.
    * 由于析构函数只能有一个，所以在构造函数中使用new [] 或者 new，在析构函数中只能选择delete [] 或 delete
    */
    return 0;
};


