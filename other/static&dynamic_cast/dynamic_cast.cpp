/**
 * dynamic_cast
 * 
 * https://learn.microsoft.com/zh-cn/cpp/cpp/dynamic-cast-operator?view=msvc-170
 * 
    对指向装箱枚举的基础类型的指针的 dynamic_cast 将在运行时失败，返回 0 而不是转换后的指针。

    如果 type-id 是指向值类型的内部指针，在运行时强制转换失败时，dynamic_cast 将不再引发异常。 强制转换现在将返回 0 指针值，而不是引发异常。
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

int main() {
    B b("Mike");
    D d("Tom", 18);
    b.say();
    d.say();
    d.getAge();
    cout << "-----" << endl;
    B* b2 = dynamic_cast<B*>(&d);
    D* d2 = dynamic_cast<D*>(&b); // error: cannot dynamic_cast 
    b2->say();
    d2->say();
    d2->getAge();
}