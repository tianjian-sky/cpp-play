#include <iostream>
#include <climits>

int main() {
    using namespace std;

    float a = 2.12e3;
    float b = 1.23e2;


    int c = 120 / 4 * 5;

    // char16_t ch1 = u'q';
    // char32_t ch2 = U'\u0000004d';
    
    cout << "Display float0:" << a << endl;
    cout << "Display float1: 1.23e2f" << endl;
    cout << "Display float2: " << 1.23e2f;
    cout << "Display float3: " << 1.23e2;

    cout << "Result of c: " << c;

    return 0;
}