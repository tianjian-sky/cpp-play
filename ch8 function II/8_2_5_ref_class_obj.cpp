#include <iostream>
#include <string>
using namespace std;

string version1 (const string & s1, const string & s2);
const string & version2 (string & s1, const string & s2);
const string & version3 (string & s1, const string & s2);

int main () {
    string input;
    string copy;
    string result;

    cout << "Enter a string:";
    getline(cin, input);
    copy = input;
    cout << "Your string entered: " << input << endl;

    result = version1(input, "***");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;
    
    result = version2(input, "###");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    cout << "Resetting original string.\n";
    input = copy;
    result = version3(input, "@@@"); // 程序崩溃 程序试图引用已经释放的内存
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    return 0; 
}

string version1 (const string & s1, const string & s2) {
    string t;
    t = s2+s1+s2;
    return t;
}

const string & version2 (string & s1, const string & s2) {
    s1 = s2+s1+s2;
    return s1;
}

const string & version3 (string & s1, const string & s2) {
    string t;
    t = s2+s1+s2; // warning: reference to local variable 't' returned
    return t;
}