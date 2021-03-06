#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <valarray> // valarray，模板类，数组最大值，最小值等操作

class Student

{
    private:
        /*
        * typedef放在类的私有部分，只可以公有私有成员都可修饰，放在类的公有部分，只能修饰公有成员
        */
        typedef std::valarray<double> ArrayDb; // 模板类
        ArrayDb scores;
        std::string name;
        std::ostream & arr_out(std::ostream &os) const;
    public:
        ArrayDb ages;
        Student() : name("Null Student"), scores() {}
        /*
        * 关闭隐式转换
        */
        explicit Student(const std::string &s) :name(s), scores() {}
        explicit Student(int n) : name("Nully"), scores(n) {}
        Student(const std::string &s, int n) :name(s),scores(n) {}
        Student(const std::string &s, const ArrayDb &a) :name(s),scores(a) {}
        Student(const char *str, const double *pd, int n):name(str),scores(pd, n) {}
        ~Student() {}
        double Average();
        const std::string & Name() const;
        double & operator[](int i);
        double operator[] (int i) const;

        friend std::istream & operator >>(std::istream & is, Student & stu);
        friend std::istream & getline(std::istream & is, Student & stu);
        friend std::ostream & operator <<(std::ostream & os, const Student & stu);
        
};


#endif