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
* 2. 约束模板友元
* 模板友元函数实例化取决于模板类被实例化时的类型。
*/

// 在类定义前面声明每个模板函数
template <typename T> void counts ();
template <typename T> void reports (T &);

template <typename TT>
class HasFriend {
    private:
        TT item;
    public:
        static int ct;
        HasFriend(const TT &i) : item(i) {ct++;}
        ~HasFriend() {ct--;}
        friend void counts <TT> ();
        friend void reports <> (HasFriend<TT> &);
};

template <typename T>
int HasFriend<T>::ct = 0;

template <typename T>
void counts () {
    cout << "----------\ntemplate size: " << sizeof (HasFriend<T>) << "; ";
    cout << "template count: " << HasFriend<T>::ct << "\n----------" <<endl;
}
template <typename T>
void reports (T &hf) {
    cout << "HasFriend<T>: "<< hf.item << endl;
}



int main() {
    cout << "No object declared: " << endl;
    HasFriend<int> hf1(10);
    HasFriend<int> hf2(20);
    HasFriend<double> hf3(99.99);
    HasFriend<long> hf4(19999);
    counts<int>();
    counts<double>();
    counts<long>();
    
    cout << "After declared:" << endl;
    counts<int>();
    counts<double>();
    counts<long>();
    reports< HasFriend<int> >(hf1);
    reports< HasFriend<int> >(hf2);
    reports< HasFriend<double> >(hf3);
    reports< HasFriend<long> >(hf4);
    return 0;
}