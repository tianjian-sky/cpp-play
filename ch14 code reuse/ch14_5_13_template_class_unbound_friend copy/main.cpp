#include "iostream"
using std::cin;
using std::cout;
using std::endl;

/*
* 模版与友元
* 3.模版类的非约束模版友元函数 
*
*/

template <typename T>
class HasFriend {
    private:
        T item;
        static int ct;
    public:
        HasFriend(const T & i) : item(i) {ct++;};
        template <typename C, typename D> friend void show2(C &, D &);
};
template <typename TT>
int HasFriend<TT>::ct = 0;

template <typename C, typename D> void show2(C & c, D & d) {
    cout << c.item << ", " << d.item << endl;
};

int main () {
    HasFriend<int> hfi1(10);
    HasFriend<int> hfi2(20);
    HasFriend<double> hfi3(10.5);
    show2(hfi1, hfi3);
}


