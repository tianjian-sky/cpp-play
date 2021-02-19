#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include <string>

class Worker {
    private:
        std::string fullName;
        long id;
    public:
        Worker():fullName("no one"), id(0L) {
            std::cout << "constructor Worker() called:" << std::endl;
        }
        Worker(const std::string &s, long n):fullName(s), id(n) {
            std::cout << "constructor Worker(const std::string &s, long n) called:" << std::endl;
        }
        virtual ~Worker() = 0;
        virtual void Set();
        virtual void Show() const;
};

class Waiter : virtual public Worker {
    private:
        int panache;
    public:
        Waiter() : Worker(), panache(0) {
            std::cout << "constructor Waiter() called:" << std::endl;
        }
        Waiter(const std::string &s, long n, int p = 0) : Worker(s, n), panache(p) {
            std::cout << "constructor Waiter(const std::string &s, long n, int p = 0) called:" << std::endl;
        }
        void Set();
        void Show() const;
};

class Singer : virtual public Worker {
    protected:
        enum {other, alto, contralto, soprano, bass, baritone, tenor};
        enum {Vtypes = 7};
    private:
        static char *pv[Vtypes];
        int voice;
    public:
        Singer() : Worker(), voice(other) {
            std::cout << "constructor Singer() called:" << std::endl;
        }
        Singer(const std::string &s, long n, int v = other) : Worker(s, n), voice(v) {
            std::cout << "constructor Singer(const std::string &s, long n, int v = other) called:" << std::endl;
        }
        void Set();
        void Show() const;
};

class Singer_Waiter : public Singer, public Waiter {
    
    public:
        /*
        * 派生类的构造函数的成员初始化列表中必须列出对虚基类构造函数的调用；如果未列出，则表示使用该虚基类的缺省构造函数。
        * 显然，虚继承中，虚基类的构造函数只会创建一次，因此需要确保手动调用，否则只会调用到虚基类的缺省构造函数，
        * 程序禁止像普通继承那样，调用上一级的构造函数后，再根据上一级构造函数的初始化列表自动调用虚基类的构造函数。
        */
        Singer_Waiter(const std::string &s, long n, int p = 0, int v = 0) : Singer(s, n, v), Waiter(s, n, p) {
            std::cout << "constructor Singer_Waiter(const std::string &s, long n, int p = 0, int v = 0) called:" << std::endl;
        }
        /*
        * 最远派生类必须重写虚基类中的虚方法
        */
        void Set();
        void Show() const;
};

#endif