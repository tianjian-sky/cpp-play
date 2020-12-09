#include <iostream>


double refcube0 (double &a) {
    return a * a * a;
}

double refcube (const double &a) {
    return a * a * a;
}
/**
* 引用参数声明为常量引用
* 1. 防止引用被修改
* 2.可以接收常量和非常量参数
* 3. 正确生成并使用临时变量
*/

/**
* 如果引用参数是const，将在以下两种情况创建临时变量
* 1) 实参类型正确，但不是左值
* 2） 实参类型不正确，但可以转换为正确的类型
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

    /**
    lvalue 可修改的内存块 
    rvalue： 不能通过地址访问的值，指的是不指向任何地方，一般都是temporary and short lived;
    而lvalue则相反，一般都是作为变量保存；
    很多时候也被认为是“=”左右两边；
    或者理解为，lvalue是一个container; rvalue是container的things;
    int y;
    521 = y; // error
    */

    /*
    * 引用返回类型是左值
    * 非引用返回类型是右值，这种返回值位于临时内存单元中，下一条语句执行时就可能不存在
    */


    const double temp = 1;
    double c1_0 = refcube0(side);
    double c2_0 = refcube0(*pd);
    double c3_0 = refcube0(refSide);
    double c4_0 = refcube0(lens[1]);
    double c5_0 = refcube0(edge); // error: invalid initialization of non-const reference of type 'double&' from an rvalue of type 'double'
    double c6_0 = refcube0(3.0); // error: invalid initialization of non-const reference of type 'double&' from an rvalue of type 'double
    double c7_0 = refcube0(side + 1.0 - 1.0); //  error: invalid initialization of non-const reference of type 'double&' from an rvalue of type 'double'    
    // 常规引用不能接收const
    // cout << "c0:" << refcube0(temp)<<endl;  error: binding 'const double' to reference of type 'double&' discards qualifiers

    cout << "c1:" << c1 << endl;
    cout << "c2:" << c2 << endl;
    cout << "c3:" << c3 << endl;
    cout << "c4:" << c4 << endl;
    cout << "c5:" << c5 << endl;
    cout << "c6:" << c6 << endl;
    cout << "c7:" << c7 << endl;

    return 0; 
}
