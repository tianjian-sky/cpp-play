#include <iostream>
#include "tv.h"

int main() {
    using namespace std;
    Tv s42;
    cout << "Init settings for 42 Tv " << endl;
    s42.volup();
    // s42.settings();
    s42.onoff();
    // s42.chanup();

    Remote grey;
    grey.set_chan(s42, 10);
    // grey.volup(s42);
    // s42.settings();

}