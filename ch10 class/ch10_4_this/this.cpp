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
struct myStruct {
    int age;
};

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
        void show() const; // Promise not to change invoking object

        const Stock & topval(const Stock &) const;

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
void Stock::acquire(const std::string &co, long n, double pr) {
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

void Stock::buy(long num, double price) {
    if (num < 0) {
        std::cout << "Number of shares purchased cant be negative." << "Transaction is aborted." << std::endl;
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    using std::cout;
    if (num < 0) {
        cout << "Number of shares sold cant be negative." << "Transaction is aborted." << std::endl;
    } else if (num > shares) {
        cout << "You cant sell more than you have! " << "Transaction is aborted." << std::endl; 
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

void Stock::show() const {
    std::cout << "Company: " << company
    << " Shares: " << shares << '\n'
    << " Share Price: $" << share_val
    << " Total Worth: $" << total_val << std::endl;
}

const Stock & Stock::topval(const Stock &s) const {
    if (s.total_val > this->total_val) {
        return s;
    } else {
        return *this;
    }
}


int main () {

    myStruct ms = {1};
    const myStruct ms2 = {2};
    // ms2.age = 3; // error: assignment of member 'myStruct::age' in read-only object

    
    const Stock fluffy_the_cat = Stock("NanoSmart", 20, 12.50); // error: passing 'const Stock' as 'this' argument discards qualifiers [-fpermissive]
    const Stock fluffy_the_cat2 = Stock("Hello", 30, 5.5);


    /**
     * 这行将要报错，因为接下来的函数调用无法保证不会修改const Stock，必须要显示地声明这些函数调用不会修改对象
     * 然而类的成员函数所使用的类对象是由方法调用隐式提供地，因此需要声明方法为const成员
    */
    fluffy_the_cat.show();
    fluffy_the_cat2.show();
    std::cout << "Winner is:" << std::endl;
    fluffy_the_cat.topval(fluffy_the_cat2).show();
    return 0;
}