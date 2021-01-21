#include <iostream>
#ifndef STRING_H_
#define STRING_H_

using std::ostream;
using std::istream;

class String {
    private:
        char * str;
        int len;
        static int num_strings;
        static const int CINLIM = 80;
        
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

        String (const char *s);
        String();
        String(const String &);
        ~String();
        int length () const {return len};
        // overload operator
        String & operator=(const String &);
        String & operator=(const char *);
        char & operator[](int i);
        const char & operator[](int i) const;
        friend bool operator<(const String &st, const String &st2);
        friend bool operator>(const String &stl, const String &st2);
        friend bool operator==(const String &st, const String &st2);
        friend ostream & operator << (ostream &os, const String &st);
        friend istream & operator>> (istream &is, String &st);
        static int HowMany();
};

#endif