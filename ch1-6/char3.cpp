#include <iostream>
#include <climits>

int main() {
    using namespace std;
    char ch = '\x4d'; // ok
    // char ch = '\u004d'; // ok
    // char ch = 'M'; // ok
    // char ch = 77; // ok
    // char ch = \u004d; // universal character \u004d is not valid in an identifier
    
    int i = ch;

    // char16_t ch1 = u'q';
    // char32_t ch2 = U'\u0000004d';

    cout << "Display char: " << ch << endl;
    cout << "Display char2: \x4d" << endl;
    cout << "Display special char: \a\n";
    cout << "Display iso-10616 char: \u004d\n";
    // cout << "Display char16_t char: " << ch1 << endl;
    // cout << "Display char32_t char: " << ch2 << endl;

    return 0;
}