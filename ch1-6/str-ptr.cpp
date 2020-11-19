#include <iostream>
using namespace std;
struct str {
    char name[20];
    float volume;
    double price;
};
int main() {
    str *ps = new str;
    str strn = {
        "hello",
        3,
        100
    };
    cout << "enter name";
    cin.get(ps->name, 20);
    cout << "enter volume";
    cin >> (*ps).volume;

    cout << ps->name <<endl;
    // cout <<strn->name <<endl; error: base operand of '->' has non-pointer type 'str'
    // cout << ps.name <<endl; request for member 'name' in 'ps', which is of pointer type 'str*' (maybe you meant to use '->' ?)
    cout << (*ps).volume << endl;

    cout << ps << endl;

    cout << (int *) ps << endl;

    cout << strn.name << endl;

    cout << &strn << endl;
    cout <<(int *) strn.name << endl;

    return 0;
}