#include <iostream>
using std::cout;
#include "stonewt.h"
void display(const Stonewt &st, int n);


Stonewt displayByPassValue(const Stonewt st, int n);
/**
 * c++ 自动提供以下成员函数
 * 默认构造函数 （如果没有定义构造函数）
 * 默认析构函数 （如果没有定义）
 * 复制构造函数 （如果没有定义）也叫：拷贝构造函数
 * 赋值运算符 （如果没有定义）
 * 地址运算符 （如果没有定义）
 * 
 * 移动构造函数
 * 移动赋值运算符
*/

/**
 * c++ 类对象初始化
 * 1.复制初始化（int a = 5;）
 * 2.直接初始化（int a(5);） 
 * A x(2);　　//直接初始化，调用构造函数
 * A y = x;　　//复制初始化，调用复制构造函数
 */

/**
 * 复制构造函数
 * Class_name(const Class_name &);
 * 有何功能：逐个复制非静态成员的值
 * 
*/

/**
 * 在C++中，下面三种对象需要调用拷贝构造函数（有时也称“复制构造函数”）：
    1) 一个对象作为函数参数，以值传递的方式传入函数体；
    2) 一个对象作为函数返回值，以值传递的方式从函数返回；
    3) 一个对象用于给另外一个对象进行初始化（常称为赋值初始化）；
    如果在前两种情况不使用拷贝构造函数的时候，就会导致一个指针指向已经被删除的内存空间。对于第三种情况来说，初始化和赋值的不同含义是拷贝构造函数调用的原因。事实上，拷贝构造函数是由普通构造函数和赋值操作符共同实现的。描述拷贝构造函数和赋值运算符的异同的参考资料有很多。
*/

int main () {

    Stonewt incognito = (Stonewt) (double)275; // 如果有二义性，则放弃尝试 (不能有多个匹配的转换函数)
    Stonewt wolfe((double)285.7); // 隐式转换场景 e）上述任何情况下，使用可转换为double类型的内置函数时
    Stonewt taft((double)21, 8);


    /**
    Java和C++中new用法的区别

    C++：
    用new初始化一个对象是：Test *test=new Test();或是BirthDate *b1=new BirthDate(7,7,1970);此时new运算返回的是一个指向新分配内存首地址的类型的指针。
    如果建立的对象是一个基本类型变量，初始化过程就是赋值。如：int *point=new int(2);
    */

    /**
    new创建对象和直接定义的区别

    (1)CFont myFont;／／定义了myFont变量，然后就可以直接用myFont变量了
    (2)CFont myFont = new CFont();//myFont也可以直接使用了
    这两个有什么区别吗?

    1.  内存管理方式
        第一个系统管理内存
        第二个需要自己管理释放
    2.  空间分配的位置不一样 
        直接创建是编译器就留出了空间，在程序装入的数据段里
        用new创建的空间是运行期在堆空间分配，用完后要自己记得归还（delete）
    */

    Stonewt * s2 = new Stonewt((double)277);

    /**
    * 转换过程中生成临时变量，过后临时变量立即销毁，所以调用了析构函数
    */
    cout << "segment 2: cast using constructor" << std::endl;
    incognito = (Stonewt) (double) 1;

    
    /*
    * 类对象初始化
    */
    cout << "segment 3: initial using constructor" << std::endl;
    Stonewt s3 ((double) 3);
    

    /**
    * 函数实参需要转换，在入函数时调用构造函数，
    * 此临时变量在函数结束时销毁，调用析构函数
    */
    cout << "segment 4: cast during function parameter" << std::endl;
    display((double) 3, 1);

    /* 
    * 两边都是同类型，不用转了，也不会产生临时变量
    */
    cout << "segment 5: a = b same type" << std::endl;
    incognito = s3;


    // 测试复制构造函数
    cout << "segment 6: class instance clone initialization" << std::endl;
    Stonewt s4 = incognito;

    cout << "Segment 7 pass instance to func by value" << std::endl;
    Stonewt s5 = displayByPassValue(s4, 1);


    cout << "main function end." << std::endl;
    return 0;
}

void display(const Stonewt &st, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Wow! ";
        st.show_stn();
    }
}


Stonewt displayByPassValue(const Stonewt st, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Wow! ";
        st.show_stn();
    }
    return st;
}
