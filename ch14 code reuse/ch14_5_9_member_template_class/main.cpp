#include "stacktp.h"
using std::cin;
using std::cout;
using std::endl;

/*
* 成员模板
* 1. 如何在模板类中定义模板类，及模板类成员
* 2. 如何在模板类中定义模板成员方法。
*/
int main() {
    beta<double> guy(3.5, 3);
    cout << "T was set to double" << endl;
    guy.Show();
    cout << "V was set to T, which is double, then V was set to int" << endl;
    cout << guy.blab(10, 2.3) << endl;
    cout << "U was set to int" << endl;
    cout << guy.blab(10.0, 2.3) << endl;
    cout << "U was set to double" << endl;
    cout << "Done" << endl;
    
    return 0;
}