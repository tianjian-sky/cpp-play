#include <iostream>
#include <climits>

int main() {
    using namespace std;
    int a[1];
    int b[1];

    b = a;

    cout << sizeof a << endl;

    return 0;
}