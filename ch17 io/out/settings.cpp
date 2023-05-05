/*
    ios              ->      streambuf
    一般流属性                 缓冲区管理
    一个streambuf指针         

    ostream         istream
    输出方法            输入方法
    ｜              /
    ｜          /
    iostream
    多继承 osrream，isream
*/

/*
设置打印格式 8，16，10进制
*/

#include <iostream>
#include <string>

using namespace std;

int main () {
    int n = 13;
    cout << n << endl; // 13
    cout << hex << n << endl; // d
    cout << oct << n << endl; // 15
    cout << dec << n << endl; // 13
}