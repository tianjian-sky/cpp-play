#include <iostream>
/**
 * 类作用域
*/

/**
 * 类中的常量成员变量初始化。
 * 1) 构造函数的成员初始化表
 * 2） 枚举
 * 3） static
*/

class Ik {
    private:
        int fuss;
        /**
         * 在类中声明变量为const类型，但是不可以初始化
         * const常量的初始化必须在构造函数初始化列表中初始化，而不可以在构造函数函数体内初始化
         * 
         *  带有成员初始化表的构造函数的一般形式如下:
            类名::构造函数名([参数表])[:(成员初始化表)]
            {
                // 构造函数体
            }
            成员初始化表的一般形式为：
            数据成员名1(初始值1),数据成员名2(初始值2),……
        */
        const int classConstMember;
        
    public:
        /**
         * 类中的常量成员变量初始化
        * 1) 通过构造函数的成员初始化表
        */
        Ik(int f = 9, int b = 999):classConstMember(b) {fuss = f;}
        void ViewIk() const ;

        /**
         * 类中的常量成员变量初始化
        *  2) 枚举
        */
        enum {Month = 12};
        double arr[Month];
        void printArr() const;

        /**
         * 类中的常量成员变量初始化
        *  3) static
        */
       static const int staticMember = 99999;
       void printStatic() const;
};

void Ik::ViewIk() const  {
    std::cout << fuss << std::endl;
    std::cout << "const member is:" << classConstMember << std::endl;
}
void Ik::printArr () const{
    std::cout << "Array length:" << sizeof(arr) / sizeof(arr[0]) << std::endl;
}
void Ik::printStatic() const {
    std::cout << "static member is:" << staticMember << std::endl;
}
int main () {
    const Ik * pik = new Ik(0, 111);
    const Ik ee = Ik(8, 222);
    ee.ViewIk();
    pik->ViewIk();
    ee.printArr();
    pik->printStatic();
    return 0;
}