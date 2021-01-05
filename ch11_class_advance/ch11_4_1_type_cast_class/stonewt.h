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
        ~Stonewt();
        void show_lbs() const;
        void show_stn() const;
        Stonewt testReturnCast();
};

#endif
