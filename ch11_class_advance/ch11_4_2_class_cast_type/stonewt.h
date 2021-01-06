#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt {
    private:
        enum {Lbs_per_stn = 14};
        int stone;
        double pds_left;
        double pounds;
    public:
        /**
        * 关闭隐式转换
        * explicit 关键字
        */

        /**
        * 2. 转换函数
        * 将一个类的对象转换成一个类型数据
        * a. 转换函数必须是类成员
        * b. 转换函数不能指定返回类型
        * c. 转换函数不能有参数
        * d. 不能有二义性 ，比如定义了类到int,类到的转换函数，而此时却将类对象赋值给long
        **/

       /**
        * 转换函数 强制显式转换
        * explicit 关键字 -std=c++11
        **/

        // explicit Stonewt(double lbs);
        Stonewt(double lbs);
        Stonewt(long lbs);
        Stonewt(int stn, double lbs);
        Stonewt();
        ~Stonewt();
        void show_lbs() const;
        void show_stn() const;
        Stonewt testReturnCast();
        // conversion functions
        explicit operator int() const;
        explicit operator double()const;
};

#endif
