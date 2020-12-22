#ifndef STOCK00_H_

#define STOCK00_H_
#include <string>


/**
 * 定义位于类中的方法都自动成为内联函数
*/
/*
* 单独提供函数的定义是通常的做法
*/
class Stock {
    private:
        std::string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot() { total_val = shares * share_val; }

    public:
        void acquire(const std::string &co, long n, double pr);
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show();
};

#endif