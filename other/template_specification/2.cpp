/*
类模板的特化 + 全特化和偏特化(半特化)：

1. 全特化：

 全特化即是将模板参数列表中所有的参数都确定化。

2. 偏特化(半特化):

 任何针对模版参数进一步进行条件限制设计的特化版本。

*/

#include "iostream"
using namespace std;

template <class T1, class T2>
class Data {
    public:
        void show () {
            cout << "1" << endl;
        }
};


template <>
class Data<int, double> {
    public:
        void show () {
            cout << "2" << endl;
        }
};

// 偏特化
// 1.部分参数特化
template <class T1>
class Data <T1, float>{
    public:
        void show () {
            cout << "3" << endl;
        }
};

template <class T1, class T2>
class Data <T1*, T2*>{
    public:
        void show () {
            cout << "4" << endl;
        }
};



int main() {
    Data<char, long> d1;
    d1.show();
    Data<int, double> d2;
    d2.show();
    Data<int, float> d3;
    d3.show();
    Data<int*, float*> d4;
    d4.show();
}