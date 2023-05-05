

/**
 * typedef
 * 
 * using 创建别名
 *  类似typedef
 *  也可用与模版部分具体化
 * 
*/
#include <iostream>
#include <string>
using namespace std;

template<class T>
class Base{
public:
    T x;
    T operator * (T b) {
        return x * b;
    }
};

using namespace std;

//函数声明

// template<class T>
// typedef  decltype(declval<Base<T>>() * declval<int>()) myType; // 此处不能typedef

template<class T>
using myType1 = decltype(declval<Base<T>>() * declval<int>());

myType1<int> arrowFn0 (Base<int> b, int a);

// auto arrowFn (Base b, int a) -> decltype(b*a);

//decltype类型推导
int main () {
    int n = 100;

    const Base<int> obj{10};
    //带有括号的表达式
    //加法表达式
    int nn = 0, m = 0;

    cout << arrowFn0(obj, n) << endl;

}

myType1<int> arrowFn0 (Base<int> b, int a) {
    return b.x * a;
}
