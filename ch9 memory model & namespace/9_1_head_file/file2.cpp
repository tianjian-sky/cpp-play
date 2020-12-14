#include <iostream>
#include <cmath>
#include "coordin.h"
#include "./coordin.h"

using namespace std;


void show_polar(polar dapos) {
    using namespace std;
    const double Rad_to_deg = 57.29577951;
    cout << "distance = " << dapos.distance;
    cout << " , angle = " << dapos.angle * Rad_to_deg;
    cout << " degrees" << endl;
}