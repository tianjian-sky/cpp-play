#include <iostream>

/**
* 函数模板：使用泛型来定义参数
* 函数模板的隐式实例化
* 函数模板的显式实例化
* 显示具体化
* 常规函数 > 具体化模板 > 常规模板
*/


/**
隐式实例化：后面有程序用了，编译器才会根据模板生成一个实例函数，
显式实例化：是无论是否有程序用，编译器都会生成一个实例函数，
显示具体化：因为对于某些特殊类型，可能不适合模板实现，需要重新定义实现，此时就是使用显示具体化的场景
*/

struct job {
    char name[40];
    double salary;
    int floor;
};

// 匹配优先级： 常规函数 > 具体化模板 > 常规模板
// void Swap(int a, int b);

template <typename T>
void Swap(T &a, T &b);

/*
* 显式实例化
* 在不发生函数调用的时候讲函数模板实例化，或者在不适用类模板的时候将类模板实例化称之为模板显示实例化。
*/
template void Swap <char>(char &a, char &b); // 为char类型生成一个Swap函数实例
/**
* 显示具体化
*/
template <> void Swap<job>(job &a, job &b);

void Show(job &j);

int main () {
    using namespace std;
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    int i = 10, j = 20;
    cout << "i,j=" << i << " , " << j << endl;
    cout << "Using compile generated int swapper:" << endl;
    Swap(i, j);
    cout << "Now i,j=" << i << " , " << j << endl;

    job sue = {"Susan Yaffee", 73000.60, 7};
    job sidney = {"Sidney Taffee", 99999.99, 9};
    cout << "Before Swap job:" << endl;
    Show(sue);
    Show(sidney);
    Swap(sue, sidney);
    cout << "After job swap:" << endl;
    Show(sue);
    Show(sidney);

    char ch1 = 'a';
    char ch2 = 'b';
    Swap<char>(ch1, ch2); // FIXME: 不起作用
    return 0; 
}

// void Swap(int a, int b) {
//     using namespace std;
//     cout << "normal function called" << endl;
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }

template <typename T>
void Swap(T &a, T &b) {
    using namespace std;
    cout << "normal functin template called" << endl;
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <> void Swap<job>(job &a, job &b) {
    using namespace std;
    cout << "explitation functin template called" << endl;
    double t1;
    int t2;
    t1 = a.salary;
    a.salary = b.salary;
    b.salary = t1;
    t2 = a.floor;
    a.floor = b.floor;
    b.floor = t2;
}

void Show(job &j) {
    using namespace std;
    cout << j.name << "$:" << j.salary << "on floor " << j.floor << endl;
}
