#include <iostream>
#include <cmath>
#include "coordin.h"
#include "./coordin.h"

using namespace std;

extern int global;
extern int int_one; // error, static duration but internal linkage！  undefined reference to `int_one'

void show_polar(polar dapos) {
    using namespace std;
    const double Rad_to_deg = 57.29577951;
    cout << "distance = " << dapos.distance;
    cout << " , angle = " << dapos.angle * Rad_to_deg;
    cout << " degrees" << endl;
    cout << "static duration, global linkage: " << global << endl;
    cout << "static duration, internal linkage: " << int_one << endl;
    // cout << "static duration, internal linkage: " << int_one << endl; error: static duration, internal linkage;
}

polar rect_to_polar(rect xypos) {
    using namespace std;
    polar answer;

    answer.distance = sqrt(xypos.x*xypos.x + xypos.y*xypos.y);
    answer.angle = atan2(xypos.y, xypos.x);
    return answer;
}