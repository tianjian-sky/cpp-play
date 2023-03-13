#include "iostream"
using std::cin;
using std::cout;
using std::endl;

/*
* 模版与友元
* 2.模版类的约束模版友元函数 
*
*/
template <typename TT> void counts();
template <typename TT> void reports(TT &);

template <typename T>
class HasFriend {
    private:
        T item;
        static int ct;
    public:
        HasFriend(const T & i) : item(i) {ct++;};
        ~HasFriend() {ct--;};
        friend void counts<T>();
        friend void reports<>(HasFriend<T> &);
};

template <typename TT>
int HasFriend<TT>::ct = 0;

template <typename TT>
void counts () {
    cout << "size:" << sizeof(HasFriend<TT>) << "; " << endl;
    cout << "count:" << HasFriend<TT>::ct << "; " << endl;
}

template <typename TT>
void reports (TT & hf) {
    cout << "HasFriend<T>:" << hf.item << "; " << endl;
}

int main () {
    HasFriend<int> hfi1(10);
    HasFriend<int> hfi2(20);
    HasFriend<double> hfi3(10.5);
    counts<int>();
    counts<double>();
    // reports(hfi1);
    // reports(hfi2);
    // reports(hfi3);
}


