#include <iostream>
#ifndef STRINGBAD_H_
#define STRINGBAD_H_

class StringBad {
    private:
        char * str;
        int len;

        
        int a;
        int b;

        /*
        * You cannot define static enum in C++.  static can only be the variable of the enum, not the type itself!
        * 
        * static enum {A, B, C, D}; // error: a storage class can only be specified for objects and functions
        */
        enum {A, B, C, D};
        static long arr[D];

    public:
        int c;
        int d;
        /**
         * c++11 以下，不能在类声明中初始化静态成员变量
         * 
        */
        /*
         * 例外：可以在类声明中初始化的静态成员
        * 1）const整型
        * 2）枚举型
        * class xxx {
        *   static const int canInitMember = 1;
            enum {A, B, C, D};
        * }
        */
        static int num_strings;
        const static int canInitMember = 1;


        /*
        * C++11允许了类在声明的时候直接给Non-static Data Member复值。
        */
        int memberInitInDefination = 3;

        /*
        * 3.类的enum类型成员的访问
        */
        enum {S, M, L, XL};
        enum class_typed_enum {alpha = 1001, beta, gamma} class_typed_enum_var1, class_typed_enum_var2;

        StringBad(const char *s);
        StringBad();
        StringBad(const StringBad &sb);
        ~StringBad();
        // friend function
        friend std::ostream & operator << (std::ostream &os, const StringBad &st);
};

#endif