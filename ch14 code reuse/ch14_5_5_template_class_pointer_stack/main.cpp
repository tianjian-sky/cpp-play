#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stack.h"

const int Num = 10;
int main() {
    std::srand(std::time(0));
    std::cout << "Please enter stack size: ";
    int stackSize;
    std::cin >> stackSize;
    Stack<const char *> st(stackSize);

    const char * in[Num] = {
        "1: HG",
        "2: KI",
        "3: BR",
        "4: IF",
        "5: WK",
        "6: PK",
        "7: JA",
        "8: XP",
        "9: JM",
        "10:MM"
    };

    const char * out[Num];
    int processed = 0;
    int nextin = 0;
    while (processed < Num) {
        if (st.isempty()) {
            st.push(in[nextin++]);
        } else if (st.isfull()) {
            st.pop(out[processed++]);
        } else if (std::rand() % 2 && nextin < Num) {
            st.push(in[nextin++]);
        } else {
            st.pop(out[processed++]);
        }
    }
    for (int i = 0; i < Num; i++) {
        std::cout << out[i] << std::endl;
    }
    std::cout << "Bye" << std::endl;
    return 0;
}