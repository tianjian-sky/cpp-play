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
        * 当关闭隐式转换时出现如下报错信息：
        * 这也就说明 = 操作符被重载了
        * .\stonewt.h:4:7: note: candidate: Stonewt& Stonewt::operator=(const Stonewt&)
        * class Stonewt {
        *   ^
        *.\stonewt.h:4:7: note:   no known conversion for argument 1 from 'double' to 'const Stonewt&'
        **/

        // explicit Stonewt(double lbs);
        Stonewt(double lbs);
        Stonewt(long lbs);
        Stonewt(int stn, double lbs);
        Stonewt();
        // 复制构造函数
        Stonewt(const Stonewt &);
        ~Stonewt();
        void show_lbs() const;
        void show_stn() const;
        Stonewt testReturnCast();
        // 赋值运算符重载

        /**
         * 临时变量作为引用参数传入，必须使用const引用接收
         * 
         * 就拿f(a + b)来说，a+b的值会存在一个临时变量中，
         * 当把这个临时变量传给f时，由于f的声明中，参数是int&，不是常量引用，因为c++编译器的一个关于语义的限制。
         * 如果一个参数是以非const引用传入，c++编译器就有理由认为程序员会在函数中修改这个值，并且这个被修改的引用在函数返回后要发挥作用。
         * 但如果你把一个临时变量当作非const引用参数传进来，由于临时变量的特殊性，程序员并不能操作临时变量，而且临时变量随时可能被释放掉，
         * 所以，一般说来，修改一个临时变量是毫无意义的，据此，c++编译器加入了临时变量不能作为非const引用的这个语义限制。
         * 
         * https://blog.csdn.net/u011068702/article/details/64443949
         */
        Stonewt & operator= (const Stonewt &);
};

#endif
