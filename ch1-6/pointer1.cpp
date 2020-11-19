#include <iostream>
using namespace std;

int main() {
    int * pt = new int;
    *pt = 1001;


    double * pt2 = new double;

    *pt2 = 12345.32212;

    int * pt3 = new int [10];

    pt3[0] = 1;
    pt3[1] = 2;
    pt3[2] = 3;

    double arr[5] = {1,2,3,4,5};

    double * pt4 = arr;

    cout << "sizeof pt:" << sizeof(pt) << endl;
    cout << "sizeof *pt:" << sizeof(*pt) << endl;
    cout << "sizeof pt2:" << sizeof(pt2) << endl;
    cout << "sizeof *pt2:" << sizeof(*pt2) << endl;

    cout << "pt3's value:" << pt3[0] << endl;
    pt3 +=1;
    cout << "pt3's value:" << pt3[0] << endl;

    cout << "sizeof array:" << sizeof(arr) << endl;
    cout << "sizeof pt:" << sizeof(pt4) << endl;
    return 0;
}