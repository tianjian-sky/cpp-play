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
enum egg {XS, S, M, L, XL};
enum t_shirt {XS, S, M, L, XL};

enum class egg {XS, S, M, L, XL};
enum class t_shirt {XS, S, M, L, XL};

egg someEgg = egg::S;
t_shirt someT = t_shirt::XL;

class Ik {
    private:
        int fuss;
        const int classConstMember;
        
    public:
        Ik(int f = 9, int b = 999):classConstMember(b) {fuss = f;}
        void ViewIk() const ;

        enum {Month = 12};
        double arr[Month];
        void printArr() const;

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