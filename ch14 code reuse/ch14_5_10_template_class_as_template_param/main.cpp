#include "stacktp.h"
#include "iostream"
using std::cin;
using std::cout;
using std::endl;

/*
* 模板可以包含：
* 类型参数
* 非类型参数
* 模板
*/


template <template <class T> class Thing> // Thing必须是一个模板类，声明与template <class T> 匹配
class Crab {
    private:
        Thing<int> s1;
        Thing<double> s2;
    public:
        Crab() {};
        bool push(int a, double x) {
            return s1.push(a) && s2.push(x);
        }
        bool pop(int &a, double &x) {
            return s1.pop(a) && s2.pop(x);
        }
};
/*
* 成员模板
* 1. 如何在模板类中定义模板类，及模板类成员
* 2. 如何在模板类中定义模板成员方法。
*/
int main() {
    Crab<Stack>nebula;
    int ni;
    double nb;
    cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):" << endl;
    while(cin >> ni >> nb && ni > 0 && nb > 0) {
        if (!nebula.push(ni, nb)) {
            break;
        }
    }
    while (nebula.pop(ni, nb)) {
        cout << ni << ", " << nb << endl;
    }
    cout << "Done." << endl;
    
    return 0;
}