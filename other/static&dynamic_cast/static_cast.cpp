/**
 * static_cast
 * 
 * https://learn.microsoft.com/zh-CN/cpp/cpp/static-cast-operator?view=msvc-170
 * 
 * 运算符可用于将指向基类的指针转换为指向派生类的指针等操作。 此类转换并非始终安全。
 * 
 *  static_cast 转换安全性不如 dynamic_cast 转换，因为 static_cast 不执行运行时类型检查，而 dynamic_cast 执行该检查。 对不明确的指针的 dynamic_cast 将失败，而 static_cast 的返回结果看似没有问题；这是危险的。 
 * 
 * static_cast 运算符可以将整数值显式转换为枚举类型。 如果整型值不在枚举值的范围内，生成的枚举值是不确定的。

 * static_cast 运算符将空指针值转换为目标类型的空指针值。

 * 任何表达式都可以通过 static_cast 运算符显式转换为 void 类型。 目标 void 类型可以选择性地包含 const、volatile 或 __unaligned 特性。

 * static_cast 运算符无法转换掉 const、 volatile或 __unaligned 特性。 有关移除这些特性的详细信息，请参阅 const_cast Operator。
 * 
 */
#include <iostream>
using std::cout;
using std::endl;
class B {
    public:
        B(std::string name):name(name) {}
        std::string name;
        void say();
};
void B::say() {
    cout << (std::string) "My name is:" << name << endl;
}
class D : public B {
    public:
        D(std::string name, int age):B(name),age(age) {}
        int age;
        void getAge();
};
void D::getAge() {
    cout << "My age is:" << age << endl;
}

void f(B* b, D* d) {
   D* pd2 = static_cast<D*>(b);   // Not safe, D can have fields
                                   // and methods that are not in B.

   B* pb2 = static_cast<B*>(d);   // Safe conversion, D always
                                   // contains all of B.
}
int main() {
    B b("Mike");
    D d("Tom", 18);
    b.say();
    d.say();
    d.getAge();
    cout << "-----" << endl;
    B* b2 = static_cast<B*>(&d);
    D* d2 = static_cast<D*>(&b);
    b2->say();
    d2->say();
    d2->getAge(); // 异常
}