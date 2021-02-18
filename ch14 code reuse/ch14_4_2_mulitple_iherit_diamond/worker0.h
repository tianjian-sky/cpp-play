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

class Waiter : public Worker {
    private:
        int panache;
    public:
        Waiter() : Worker(), panache(0) {
            std::cout << "constructor Waiter() called:" << std::endl;
        }
        Waiter(const std::string &s, long n, int p = 0) : Worker(s, n), panache(p) {
            std::cout << "constructor Waiter(const std::string &s, long n, int p = 0) called:" << std::endl;
        }
        Waiter(const Worker &w, int p = 0) : Worker(w), panache(p) {}
        void Set();
        void Show() const;
};

class Singer : public Worker {
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
        Singer(const Worker &w, int v = other) : Worker(w), voice(v) {
            std::cout << "constructor Singer(const Worker &w, int v = other) called:" << std::endl;
        }
        void Set();
        void Show() const;
};

class Singer_Waiter : public Singer, public Waiter {
    
};

#endif