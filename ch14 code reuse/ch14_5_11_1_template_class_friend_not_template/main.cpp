#include "iostream"
using std::cin;
using std::cout;
using std::endl;


/*
* 14.5.11 模板类的友元
* 1) 非模板友元
* 2) 约束模板友元，友元的类型取决于类被实例化时的类型
* 3) 非约束模板友元，友元的所有具体化都是类的每一个具体化的友元
*/

/*
* 1. 非模板友元
* 1.1) 该函数是非模板，不带参数列表。这类友元函数通常可以用于全局对象的访问。
* 1.2 ) 该函数不视为模板函数， 并且参数中含有模板类定义的类型变量。 因此对模板类的每个实例化版本都需要提供该函数的一个重载版本。
* https://www.cnblogs.com/heartchord/p/4822422.html
* 需要注意，这种用法g++编译器将会给出警告：warning: friend declaration ‘xxxx’ declares a non-template function [-Wnon-template-friend]
* 关闭该警告方法是加入选项-Wno-non-template-friend，例如：g++ -Wno-non-template-friend -o test test.cpp。
*/



template <typename T>
class HasFriend {
    private:
        T item;
    public:
        static int ct;
        HasFriend(const T &i) : item(i) {ct++;}
        ~HasFriend() {ct--;}
        friend void counts (); // 1.1非模板友元, 该函数是非模板，不带参数列表
        friend void reports (HasFriend<T> &); // 1.2非模板友元,该函数不视为模板函数，前面没有template指令， 并且参数中含有模板类定义的类型变量
};

template <typename T>
int HasFriend<T>::ct = 0;


void counts () {
    cout << "----------\nint count: " << HasFriend<int>::ct << "; ";
    cout << "double count: " << HasFriend<double>::ct << "; ";
    cout << "long count: " << HasFriend<long>::ct << "\n----------" <<endl;
}

void reports (HasFriend<int> &hf) {
    cout << "HasFriend<int>: "<< hf.item << endl;
}

void reports (HasFriend<double> &hf) {
    cout << "HasFriend<double>: "<< hf.item << endl;
}

void reports (HasFriend<long> &hf) {
    cout << "HasFriend<long>: "<< hf.item << endl;
}

int main() {
    cout << "No object declared: " << endl;
    counts();
    HasFriend<int> hf1(10);
    cout << "HasFriend<int> hf1(10):" << endl;
    counts();
    HasFriend<int> hf2(20);
    cout << "after HasFriend<int> hf2(20):" << endl;
    counts();
    HasFriend<double> hf3(99);
    cout << "after HasFriend<double> hf3(99):" << endl;
    counts();
    HasFriend<long> hf4(19999);
    cout << "after HasFriend<long> hf4(19999):" << endl;
    counts();
    reports(hf1);
    reports(hf2);
    reports(hf3);
    reports(hf4);
    return 0;
}