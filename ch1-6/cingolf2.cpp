#include <iostream>
const int Max = 5;
using namespace std;

int main() {
    
    char golf[Max];
    cout << "Please enter your golf scores. \n";
    cout << "You must enter " << Max << " rounds.\n";
    int i;
    for (i = 0; i < Max; i++) {
        cout << "Round #" << i+1 << ": ";
        cin >> golf[i]; // golf 是int类型，当输入数字时 类型不批配，failbit被设置，导致！cin为true
        cout << "  test cin" << cin << golf[i] << endl;
        while(!cin) {
            cin.clear();
            while(cin.get() != '\n') {
                continue;
            }
            cout << "Please enter a char:";
        }
    }

    return 0;
}