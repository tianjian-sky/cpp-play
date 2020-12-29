#ifndef MYTIME1_H_
#define MYTIME1_H_

/**
 * 友元函数
 * 非类的成员函数，但是可以访问类的私有成员 
 * 
*/ 

class Time {
    private:
        int hours;
        int minutes;
    public:
        Time();
        Time(int h, int m = 0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h=0, int m=0);
        Time operator+(const Time &t) const;
        Time operator-(const Time &t) const;
        Time operator*(double mult) const;
        friend Time operator*(double mult, const Time & t);
        friend std::ostream & operator << (std::ostream & os, const Time & t);
        void Show() const;
};

#endif
