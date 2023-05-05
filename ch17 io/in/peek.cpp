#include <iostream>

using namespace std;

int main () {
    char ch;
    while (cin.get(ch)) {   
        if (ch != '#') {
            cout << ch;
        } else {
            cin.putback(ch); // 再放入队列
            break;
        }
    }
    if (!cin.eof()) {
        cin.get(ch);
        cout << endl << ch << " is next ch." << endl;
    } else {
        cout << "End of file" << endl;
        exit(0);
    }
    while(cin.peek() != '#') {
        cin.get(ch);
        cout << ch;
    }
    if (!cin.eof()) {
        cin.get(ch);
        cout << endl << ch << " is next ch" << endl;
    } else {
        cout << "end of file" << endl;
    }
    return 0;
}