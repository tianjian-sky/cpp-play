/*
    读写文件
    ifstream 读文件
    ofstream 写文件

*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
    string filename;
    cout << "Enter file name:" ;
    cin >> filename;

    ofstream fout(filename.c_str());
    fout << "For your eyes only!\n";
    cout << "Enter your secret number: ";
    float secret;
    cin >> secret;
    fout << "Your secret number:" << secret << endl;
    fout.close();
    ifstream fin(filename.c_str());
    cout << "Here are the contents of " << filename << endl;
    char ch;
    while(fin.get(ch)) {
        cout << ch;
    }
    cout << "Done\n";
    fin.close();
}