/*
    仿函数 functor
    1.函数名
    2.函数指针
    3.类中实现一个operator()

    functor:
        * generator: 不用参数的functor
        * unary function 一个参数
        * binary function 两个参数
        * predicate 返回bool的unary function
        * binary predicate 返回bool的binary function
*/

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

template <class T>
class TooBig {
    private:
        T cutoff;
    public:
        TooBig(const T & t): cutoff(t) {}
        bool operator()(const T & v) {return v > cutoff;}
};
void outint(int n) {
    cout << n << "  ";
}

int main () {
    TooBig<int> f100(100);
    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    list<int> yadayada(vals, vals+10);
    list<int> etcetera(vals, vals+10);
    cout <<"Original" << endl;
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
    yadayada.remove_if(f100);
    etcetera.remove_if(TooBig<int>(200));
    cout << "Trimmed:"<< endl;
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;
    return 0;
}
