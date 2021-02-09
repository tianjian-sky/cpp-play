#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <valarray> // valarray，模板类，数组最大值，最小值等操作

/*
* 私有继承
* 将对象作为一个未命名对象添加到类中
* 多继承
*/
class Student : private std::string, private std::valarray<double>

{
    private:
        /*
        * typedef放在类的私有部分，只可以公有私有成员都可修饰，放在类的公有部分，只能修饰公有成员
        */
        typedef std::valarray<double> ArrayDb; // 模板类
        std::ostream & arr_out(std::ostream &os) const;
    public:
        Student() : std::string("Null Student"), ArrayDb() {}
        /*
        * 关闭隐式转换
        */
        explicit Student(const std::string &s) : std::string(s), ArrayDb() {}
        explicit Student(int n) : std::string("Nully"), ArrayDb(n) {}
        Student(const std::string &s, int n) : std::string(s), ArrayDb(n) {}
        Student(const std::string &s, const ArrayDb &a) : std::string(s), ArrayDb(a) {}
        Student(const char *str, const double *pd, int n) : std::string(str), ArrayDb(pd, n) {}
        ~Student() {}
        double Average();
        const std::string & Name() const;
        double & operator[](int i);
        double operator[] (int i) const;

        /*
        * 使用using，重新定义访问权限
        */
        using std::valarray<double>::sum;

        friend std::istream & operator >>(std::istream & is, Student & stu);
        friend std::istream & getline(std::istream & is, Student & stu);
        friend std::ostream & operator <<(std::ostream & os, const Student & stu);
        
};


#endif