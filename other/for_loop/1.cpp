#include <vector>
#include <iostream>
using namespace std;

int main () {

    vector<char> vec = {'a', 'b', 'c'};

    for (auto ch : vec) {
        cout << ch << endl;
    }
}