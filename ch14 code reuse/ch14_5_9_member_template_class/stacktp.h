#ifndef STACKTP_H_
#define STACKTP_H_
#include "iostream"
using std::cin;
using std::cout;
using std::endl;

template <typename T>
class beta {
    /*
    * 1. 如何在模板类中定义模板类，及模板类成员
    */
    private:
        template <typename V>
        class hold;
        hold <T> q;
        hold<int> n;
    public:
        beta(T t, int i) : q(t), n(i) {}
        /*
        * 2. 如何在模板类中定义模板成员方法。
        */
        template<typename U>
        U blab(U u, T t);
        void Show () const { q.show(); n.show();}
};
template <typename T>
    template <typename V>
    class beta<T>::hold{
        private:
            V val;
        public:
            hold(V v = 0) : val(v) {}
            void show() const { cout << val << endl; }
            V Value() const { return val; }
    };

template <typename T>
    template <typename U>
    U beta<T>::blab(U u, T t) {
        return (n.Value() + q.Value()) * u / t;
    }
#endif