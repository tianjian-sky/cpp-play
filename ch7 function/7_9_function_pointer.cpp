#include <iostream>

double betsy(int);
double pam(int ins);

/**
函数指针

函数返回值 （*指针变量名）（函数参数...）

*/
void estimate(int lines, double (*pf) (int));


int main () {
    using namespace std;
    int code;

    cout << "How many lines of code do you need?";
    cin >> code;
    cout << "Here's Betsy's estimate:\n";
    estimate(code, betsy);
    cout << "Here's Pam's estimate:\n";
    estimate(code, pam);
    return 0;
}

double betsy(int ins) {
    return 0.05*ins;
}

double pam(int ins) {
    return 0.03*ins + 0.004*ins*ins;
}
void estimate(int lines, double (*pf) (int)) {
    using namespace std;
    cout << lines << " lines will take ";
    cout << (*pf)(lines) << " hour(s)\n"; // 形式1
    cout << pf (lines) << " hour(s)\n"; // 形式2 函数名就是函数的指针
}
