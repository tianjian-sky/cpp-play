#include <vector>
#include <iostream>
#include <utility>
using namespace std;


/**
 * 在C++中，下面三种对象需要调用拷贝构造函数（有时也称“复制构造函数”）：
    1) 一个对象作为函数参数，以值传递的方式传入函数体；
    2) 一个对象作为函数返回值，以值传递的方式从函数返回；
    3) 一个对象用于给另外一个对象进行初始化（常称为赋值初始化）；
    如果在前两种情况不使用拷贝构造函数的时候，就会导致一个指针指向已经被删除的内存空间。对于第三种情况来说，初始化和赋值的不同含义是拷贝构造函数调用的原因。事实上，拷贝构造函数是由普通构造函数和赋值操作符共同实现的。描述拷贝构造函数和赋值运算符的异同的参考资料有很多。
*/

/*
c++ 提供默认的移动构造函数和移动赋值运算符
*/

/*
static_cast 强制转右值引用
*/

/*
std::move 强制转右值引用
*/

template<class T>
class A {
    public:
        int len;
        vector<T>* arr;
        A(int n) : len(n) {
            arr = new vector<T>(n);
        };
        A (vector<T> in) {
            len = in.size();
            arr = new vector<T>(len);
            int index = 0;
            for (T item : in) {
                arr->at(index++) = item;
            }
        }
        A (const A & in): len(in.arr->size()) {
            cout << "copy" << endl;
            len = in.arr->size();
            arr = new vector<T>(len);
            int index = 0;
            for (T item : *in.arr) {
                arr->at(index++) = item;
            }
        }
        A (A && in): len(in.arr->size()) {
            cout << "move constructor" << endl;
            len = in.arr->size();
            arr = in.arr;
            in.arr = nullptr;
        }
        A<T> operator+(const A<T>& a2) const {
            A<T> temp(len + a2.len);
            int index = 0;
            for (T item : *arr) {
                temp.arr->at(index++) = item;
            }
            for (T item : *a2.arr) {
                temp.arr->at(index++) = item;
            }
            return temp;
        }
        A<T> & operator=(A<T>&& in) {
            cout << "move =" << endl;
            len = in.arr->size();
            arr = in.arr;
            in.arr = nullptr;
        }
        void print() const {
            for (T item : *arr) {
                cout << item << " ";
            }
            cout << endl;
        }
};
int main () {
    A<int> a(10);
    vector<int> temp = {1,2,3,4,5};
    cout << "a1 = a "<< endl;
    A<int> a1 = a;
    cout << "a2(a) "<< endl;
    A<int> a2(a);
    A<int> a3(temp);
    cout << "a4(a3+a2) "<< endl;
    A<int> a4(a3+a2); // 未调用移动和拷贝构造函数，编译器进行了优化
    cout << "a5 = (a3+a2) "<< endl;
    A<int> a5 = (a3+a2); // 未调用移动和拷贝构造函数，编译器进行了优化
    cout << "a7 = static_cast<A<int>&&>(a1+a4) "<< endl;
    A<int> a7 = static_cast<A<int>&&>(a1+a4);
    cout << "a7 = move(a1+a4) "<< endl;
    // std::move 转右值引用
    A<int> a8 = move(a5);
}