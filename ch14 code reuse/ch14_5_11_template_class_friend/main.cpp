#include "iostream"
using std::cin;
using std::cout;
using std::endl;

/*
* 模版与友元
* 1.非模版友元 
*
*/

template <typename T>
class HasFriend {
    private:
        T item;
        static int ct;
    public:
        HasFriend(const T & i) : item(i) {ct++;};
        ~HasFriend() {ct--;};
        friend void counts();
        friend void reports(HasFriend<T>&);
};

template <typename T>
int HasFriend<T>::ct = 0;

void counts () {
    cout << "int count:" << HasFriend<int>::ct << "; " << endl;
    cout << "double count:" << HasFriend<double>::ct << "; " << endl;
}

void reports (HasFriend<int> & hf) {
    cout << "HasFriend<int>:" << hf.item << "; " << endl;
}

void reports (HasFriend<double> & hf) {
    cout << "HasFriend<double>:" << hf.item << "; " << endl;
}

int main () {
    counts();
    HasFriend<int> hfi1(10);
    counts();
    HasFriend<int> hfi2(20);
    counts();
    HasFriend<double> hfi3(10.5);
    counts();
    reports(hfi1);
    reports(hfi2);
    reports(hfi3);
}


