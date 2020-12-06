#include <iostream>

double refcube (const double &a) {
    return a * a * a;
}
/**
* 将引用作为参数传递
*/
int main () {
    using namespace std;

    double side = 3.0;
    double *pd = &side;
    double &refSide = side;
    long edge = 5L;
    double lens[4] = {2.0, 3.0, 10.0, 12.0};
    
    double c1 = refcube(side);
    double c2 = refcube(*pd);
    double c3 = refcube(refSide);
    double c4 = refcube(lens[1]);
    double c5 = refcube(edge);
    double c6 = refcube(3.0);
    double c7 = refcube(side + 1.0 - 1.0);

    cout << "c1:" << c1 << endl;
    cout << "c2:" << c2 << endl;
    cout << "c3:" << c3 << endl;
    cout << "c4:" << c4 << endl;
    cout << "c5:" << c5 << endl;
    cout << "c6:" << c6 << endl;
    cout << "c7:" << c7 << endl;

    return 0; 
}
