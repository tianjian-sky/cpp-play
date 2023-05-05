/*
    二进制模式：
    文件写时，不会做任何的转换。

    文本模式：
    c++ 换行：linefeed
    macintosh换行：cr
    unix,linux换行：linefeed
    windows换行：cr+lf

    window保存文本模式；
    lf -> cr+lf 
    macintosh：
    lf -> cr
    -----
    window读取文本模式；
    cr+lf --> lf 
    macintosh：
    cr --> lf
    
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    ofstream fout;
    const char num = 1;
    const string biFile = "binary";
    const string txtFile = "text";
    const char n = '\n';
    fout.open(biFile, ios_base::out | ios_base::binary );
    if (fout.is_open()) {
        fout.write((char *) &num, sizeof num);
        fout.write((char *) &n, sizeof n);
    }
    fout.clear();
    fout.close();
    ofstream fout2;
    fout2.open(txtFile, ios_base::out);
    if (fout2.is_open()) {
        fout2.write((char *) &num, sizeof num);
        fout2.write((char *) &n, sizeof n);
    }
    fout2.close();
    cout << "Finished" << endl;
}