/*
    位操作
    cin和cout都包含一个bitmask，描述各种可能出现的状态
    eofbit
    failbit
    badbit
    goodbit
*/

/*
clear(state) // 设置当前位，清楚其他位
setstate(state) // 设置当前位，其他位不影响
*/

/*
exception(state)
设置引发异常的bit 。
默认是goodbit，不会抛出异常
*/

/*
流状态

流状态位一旦被设置，流将对后面的输入或输出关闭，直到位被清除

可以通过
cin.fail()
cin.eof()

*/

#include <iostream>
#include <exception>

int main () {
    using namespace std;
    cin.exceptions(ios_base::failbit);
    cout << "Enter numbers: ";
    int sum = 0;
    int input = 0;
    try {
        while(cin >> input) {
            sum += input;
        }
    }   catch (ios_base::failure & bf) {
            cout << bf.what() << endl; // unspecified iostream_category error
            cout << "Error!" << endl;
    }
}