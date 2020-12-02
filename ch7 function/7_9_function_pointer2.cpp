#include <iostream>


/**
此三个函数原型签名相同
1. const double ar[] === coonst double *ar 
    a) 多数情况下，c++将数组名解析为数组第一个元素的地址 ar = &ar[0]
    b) 对数组名取地址，得到的是整个数组的地址， 对数组名sizeof，得到的是整个数组的大小
    c) 只有当出现在函数头或函数原型中 int *arr 和int arr[]含义才相同，代表第一个元素的指针。 此处即此情况。
2. 函数原型中，可以省略标识符
*/

const double * f1 (const double ar[], int n);
const double * f2 (const double [], int);
const double * f3 (const double *, int);



int main () {
    using namespace std;
    
    double av[3] = {1112.3, 1542.6, 2227.9};

    const double *(*p1)(const double *, int) = f1;

    /**
    C++11 auto
    变量的自动类型推断。
    auto可以在声明变量的时候根据变量初始值的类型自动为此变量选择匹配的类型，类似的关键字还有decltype。
    举个例子：
    int a = 10;
    auto au_a = a;//自动类型推断，au_a为int类型
    cout << typeid(au_a).name() << endl;
    typeid运算符可以输出变量的类型。程序的运行结果输出了
    */


    auto p2 = f2; // -std=c++11

    cout << "Using pointers to functions:" << endl;
    cout << " Address Value" << endl;
    cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
    cout << p2(av, 3) << ": " << *p2(av,3) << endl;

    /**
    [] L-R 2
    *  R-L 3
    **/
    const double *(*pa[3])(const double *, int) = {f1, f2, f3}; // 声明一个函数指针数组 []和变量名最多结合1次
    auto pb = pa;
    cout << "\n Using an array of pointers to functions:\n";
    cout << " Address Value\n";
    for (int i=0; i<3; i++) {
        cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
    }

    cout << "\n Using a pointer to a pointer to a function:" << endl;
    cout << " Address Value" << endl;
    for (int i=0; i<3; i++) {
        cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;
    }

    cout << "\n Using an array of pointers to functions style2:\n";
    cout << " Address Value\n";
    for (int i=0; i<3; i++) {
        cout << (*pb[i])(av, 3) << ": " << *(*pb[i])(av, 3) << endl;
    }


    cout << "\n Using pointers to an array of pointers:" << endl;
    cout << " Address Value" << endl;
    auto pc = &pa;
    cout << (*pc)[0](av,3) << ": " << *(*pc)[0](av,3) << endl;

    cout << "\n Using pointers to an array of pointers style2 **:" << endl;
    cout << " Address Value" << endl;
    auto pcc = &pa;
    cout << (**pcc)[0](av,3) << ": " << *(**pcc)[0](av,3) << endl;

    const double *(*(*pd)[3])(const double *, int) = &pa;
    const double * pdb = (*pd)[1](av, 3);
    cout << pdb << ": " << *pdb << endl;
    cout << (*(*pd)[2])(av, 3) << ": " << *(*(pd)[2])(av, 3) << endl;
    return 0; 
}

const double * f1 (const double * ar, int n) {
    return ar;
}
const double * f2 (const double ar[], int n) {
    return ar + 1;
}
const double * f3 (const double ar[], int n) {
    return ar + 2;
}