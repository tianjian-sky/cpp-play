#include <iostream>
#include <string>
using namespace std;
const int SIZE = 5;
void display (const string sa[], int n);

void changeString(string sa[], int n);


int main () {
    string list[SIZE];
    cout << "Enter your " << SIZE << " favourite astronomical sights: \n";
    for (int i = 0; i < SIZE; i++) {
        cout << i+1 << " : ";
        getline(cin, list[i]);
    }
    cout << "Your list:\n";
    display(list, SIZE);
    changeString(list, 3);

    cout << "After change:" << endl;
    display(list, SIZE);
    return 0;
}

void display(const string sa[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i+1 << " : " << sa[i] << endl;
    }
}

void changeString(string sa[], int n) {
    sa[n] = 'fuck xxx!';
}


