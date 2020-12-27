#include <iostream>
/**
 * 类作用域
*/

/**
* C++语言中，对于一个枚举类型（enum），其成员值在所属枚举类型的声明作用域内是不可重复
*/

/**
* 解决方案：
* 1) 不同enum封装到不同类中。
* 2) 不同enum封装到不同namespace中
* 3) C++11新增带作用域的枚举，用enum class或enum struct（两者等价）声明。 -std=c++11
*/

/**
 * 作用域内枚举不能隐式地转换为整型
 * 
*/

/**
 * 作用域枚举可以指定数据类型，必须是整型相关 (默认是int)
 * must be an integral type
*/ 

// enum egg {XS, S, M, L, XL};
// enum t_shirt {XS, S, M, L, XL};

enum weekdays {Sun, Mon, Tue, Wed, Thur, Fri, Sat};
enum class egg {XS, S, M, L, XL};
// enum class t_shirt:long {XS, S, M, L, XL}; // 枚举可以指定数据类型，必须是整型相关 (默认是int) -std=c++11
enum class t_shirt:long {XS, S, M, L, XL}; // 枚举可以指定数据类型，必须是整型相关 (默认是int) -std=c++11


class Ik {
    private:
        int fuss;
        const int classConstMember;
        
    public:
        Ik(int f = 9, int b = 999):classConstMember(b) {fuss = f;}
        void ViewIk() const ;

        enum {Month = 12};
        long arr[Month];
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
    weekdays day1, day2;
    day1 = weekdays::Thur;
    day2 = weekdays::Sun;


    egg someEgg = egg::S;
    t_shirt someT = t_shirt::XL;

    
    int castEnum = day1;
    long castClassEnum = (long) someT; // 作用域内枚举不能隐式地转换为整型

    std::cout << castEnum << std::endl;
    std::cout << (long) castClassEnum << std::endl;
    std::cout << (int) day1 << std::endl;
    std::cout << (int) someEgg << std::endl;

    return 0;
}