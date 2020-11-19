#include <iostream>
#include <ctime> // clock()
using namespace std;

int main() {
    
    float secs = 3;
    clock_t delay = secs * CLOCKS_PER_SEC;
    clock_t start = clock();

    while(clock() - start < delay);
    cout << "Done. clocks per sec is: " + CLOCKS_PER_SEC << endl;

    return 0;
}