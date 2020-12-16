#include <iostream>
const int Ar_size = 10;

struct data {
    char name[30];
    mutable int accesses;
    // int accesses; // veep.accesses += 1;  // error:assignment of member 'data::accesses' in read-only object
};


int main () {
    const data veep = {"hello world", 0};
    veep.accesses += 1; 
    
    return 0;
}

