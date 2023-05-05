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
 * 
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
        fin.open(argv[i]);
        cout << fin.good() << endl; //符合1，不符合0
        cout << fin.fail() << endl;
    }
    fin.close();
}