#include <iostream>

using namespace std;
const int LEN = 10;

void eatline() {
    while(cin.get() != '\n') {
        continue;
    }
}

int main () {
    char name[LEN];
    char title[LEN];
    cout << "Enter your name: ";
    cin.get(name, LEN); // abcdefghijklmn
    if (cin.peek() != '\n') {
        cout << "Sorry, we only have enough room for " << name << endl; // abcdefghi
    }
    eatline();
    cout << "Dear " << name << ", enter your title:" << endl;
    cin.get(title, LEN); // 123456789012345
    if (cin.peek() != '\n') {
        cout << "We were forced to truncate your title." << endl; // 1234567890
    }
    eatline();
    cout << "Name:" << name << "\n title:" << title << endl; // abcdefghi 1234567890
    
    return 0;
}