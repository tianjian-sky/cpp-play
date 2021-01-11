#include <iostream>
#ifndef STRINGBAD_H_
#define STRINGBAD_H_

class StringBad {
    private:
        char * str;
        int len;

        /**
         * 不能在类声明中初始化静态成员变量，因为声明描述了如何分配内存，但是不分配内存
        */
        // static int num_strings = 0; error: ISO C++ forbids in-class initialization of non-const static member 'StringBad::num_strings'
        static int num_strings;

        /*
         * 例外：可以在类声明中初始化的静态成员
        * 1）const整型 -std=c++11
        * 2）枚举型 -std=c++11
        */
        const int canInitMember = 1;

        enum {A, B, C, D};
        long arr[D];

    public:
        StringBad(const char *s);
        StringBad();
        ~StringBad();
        // friend function
        friend std::ostream & operator << (std::ostream &os, const StringBad &st);
};

#endif