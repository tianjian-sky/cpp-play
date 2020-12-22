#include <iostream>

/**
* 构造函数：
* 构造函数没有返回类型
* 没有定义任何构造函数时，程序会提供默认构造函数
* 提供了构造函数时，程序员必须提供默认构造函数
* 1）给已经有的构造函数的所有参数提供默认参数
* 2）通过函数重载定义一个没有参数的构造函数
*/

/**
* 析构函数：
* Stock::~Stock(){...}
* 析构函数没有参数！
* 析构函数调用时机由编译器决定，通常无需手动调用
* 必须有一个析构函数，如果没有，编译器隐式地声明一个默认析构函数 
*
*/

/**
 * 列表初始化 -std=c++11
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
        Stock() {
            std::cout << "Constructor called" << std::endl;
        }
        Stock(const std::string &co, long n, double pr) {
            company = co;
            if (n < 0) {
                std::cout << "Number of shares cant be negative; " << company << " shares set to 0." << std::endl;
                shares = 0;
            } else {
                shares = n;
            }
            share_val = n;
            set_tot();
        }
        ~Stock() {
            std::cout << "Destructor called" << std::endl;
        }
};

int main () {
    Stock fluffy_the_cat = Stock("NanoSmart", 20, 12.50);\
    /**
     * 列表初始化 -std=c++11
    */
    Stock fluffy_the_cat2 = {"NanoSmart", 20, 12.50};
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(300000, 40.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(300000, 0.125);
    fluffy_the_cat.show();
    return 0;
}