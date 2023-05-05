/*
sstream:
    与string交互
*/
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    
    ostringstream oss;

    string str;
    getline(cin, str);
    cout << str << endl;
    cin >> str;
    cout << str << endl;

}