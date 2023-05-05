/*
    读写文件
    ifstream 读文件
    ofstream 写文件

*/

/**
 * 
 * argc:
 *  参数个数，包括命令本身
 * argv:
 * 
*/

/*
ios_base::in 读 r
ios_base::out 写 w
ios_base::ate 移动到文件尾部
ios_base::app 追加到文件尾
ios_base::trunc 如果文件存在则截短文件
ios_base::binary 二进制文件

*/

// 读取第二个文件，先close,clear

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char* argv[]) {
    cout << "argc:" << argc << endl;
    ifstream fin;
    for (int i = 1; i < argc; i++) {
        fin.close();
        fin.clear();
        fin.open(argv[i], ios_base::in | ios_base::ate);
        cout << fin.good() << endl; //符合1，不符合0
        cout << fin.fail() << endl;
    }
    fin.close();
}