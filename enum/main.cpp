#include <iostream>
using namespace std;


int main () {


    /**
     * enum 标准形式：
     * enum <类型名> {<枚举常量表>} 变量名;
     * enum相当于是一个类型，因此可以定义该类型的变量。
    */
    enum my_enum_type_1 {A, B, C} e1, e2;
    enum my_enum_type_2 {X = 101, Y, Z};

    e1 = A;
    e2 = C;
    my_enum_type_2 e3 = X;

    /*
    * 1. 某个枚举类型变量只能直接被赋予此类型的枚举常量， 除非用强制转型
    */
    // e2 = Y; error: cannot convert 'main()::my_enum_type_2' to 'main()::my_enum_type_1' in assignment
    e2 = (my_enum_type_1) Y;

    cout << "e1: " << e1 << endl;
    cout << "e2: " << e2 << endl;
    cout << "e3: " << e3 << endl;

    /**
     * 2. enum可以不指定类型，如果不需要在以后声明这种类型的其他变量，就可以省略枚举类型
    */
    enum {D = 999, E = 1000, F = 1001} ne1, ne2;
    enum {S, M, L, XL};

    ne1 = F;
    cout << "no type enum with member ne1:" << ne1 << endl;

    /*
    * 3. 枚举常量可以直接使用
    */
    cout << "Using my_enum_type_1 enum member without variable: A:" << A << endl; 
    cout << "Using my_enum_type_2 enum member without variable: Y:" << Y << endl;
    cout << "Using no class enum member without variable: D:" << D << endl;  
    cout << "Using no class enum member without variable: M:" << M << endl;

    /*
    * 4.不同枚举类型中的常量名称不能重复
    * enum {alpha, beta, L}; // error: redeclaration of 'L'
    */
    // enum {alpha, beta, L}; // error: redeclaration of 'L'
}