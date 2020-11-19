#include <iostream>
using namespace std;

int main() {
    double arr[5] = { 21.1, 22.1, 23.1, 24.1, 25.1 };
    double *pt = arr;

    /*
        ## 运算符优先级
        II： 后缀++，--
        III：前缀++，--， *
    */

    /*
    
    ## 运算符结合性
    在表达式中如果有几个优先级相同的操作符，结合性就起仲裁的作用，由它决定哪个操作符先执行
    L-R： 后缀++，--
    R-L：前缀++，--， *
    R-L： 赋值

    */
    cout << "++pt" << ++pt << endl;
    cout << "*++pt" << *++pt << endl;
    cout << "++*pt" << ++*pt << endl;
    cout << "(*pt)++" << (*pt)++ << endl;
    cout << "*pt++" << *pt++ << endl;

    return 0;
}