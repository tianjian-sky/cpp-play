#include <vector>
#include <iostream>
#include <utility>
using namespace std;

/**
 * 
 * 关键字 =default 和 =delete
    在C++的类中，有四类特殊的成员函数：① 默认构造函数；② 拷贝构造函数；③ 拷贝赋值函数（operator=）；④ 析构函数；它们控制着类的实例的创建、初始化、拷贝以及销毁。

    关键字 =default 和 =delete 在这四类特殊成员函数中的应用：

（1）默认构造函数：如果对构造函数进行了重载，则编译器不会隐式的生成一个默认的构造函数，此时如果调用了默认构造函数会在编译时报错，为了避免这种情况，一般会选择重写默认构造函数，且函数体为空。关键字 =default 优化了这种行为，用该关键字标记重写的默认拷贝构造函数，编译器会隐式生成一个版本，在代码更加简洁的同时，编译器隐式生成的版本的执行效率更高。
（2）拷贝构造函数 和 拷贝赋值函数：不论有没有对它们进行重载，编译器始终会隐式生成默认版本，但有的时候不希望类实例进行拷贝构造或拷贝赋值，此时可以重写它们并将权限设置为private，但这样只是利用语法特性来碰巧实现效果，且对友元会带来困惑。可以使用关键字 =delete 标记不想被类实例调用的拷贝构造和拷贝赋值，相当于删除了它们
 * 
*/

template<class T>
class A {
    public:
        int len = 3;
        vector<T>* arr;
        A() = default;
        A(int n): len(n) {
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
        A (const A & in) = delete
        A (A && in) =- delete
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
     A<int> a; // error: no matching constructor for initialization of 'A<int>'
    cout << a.len << endl;
    A<int> a2(a); // call to deleted constructor of 'A<int>'
    A<int> a3(move(a)); // call to deleted constructor of 'A<int>'
}