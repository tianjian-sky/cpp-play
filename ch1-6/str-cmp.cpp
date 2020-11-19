#include <iostream>
using namespace std;
struct str {
    char name[20];
    float volume;
    double price;
};
int main() {
    string str1 = "hello";
    string str2 = "hello";


    bool flg = true;

    cout << (flg == false) << endl;
    cout << (str1 == str2) << endl;
    cout << (str1 == str2) << endl;

    return 0;
}