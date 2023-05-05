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

/*
设置打印宽度
*/


#include <iostream>
#include <string>

using namespace std;

int main () {
    cout.width(5);
    cout << "A" << ":";
    cout.width(8);
    cout << "B" << endl;
}