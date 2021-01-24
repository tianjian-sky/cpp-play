#include <iostream>
using std::cout;
#include "stringbad.h"

void callme1(StringBad &);
void callme2(StringBad);

int main () {
    using std::endl;
    {

        cout << "Starting an inner block." << endl;
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");

        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;


        /**
         * 1.c++11 以下，不能在类声明中初始化静态成员变量，
         * 因为声明描述了如何分配内存，但是不分配内存
         * 
         * A C++ class definition is like a blueprint for something that doesn't exist yet, as such until you actually create an instance of the class, there is no variable to set to zero at initialisation. This is what the compiler is complaining about.
         * The only time that this would be valid is if the variable was declared static, but this would mean that every single instance of the class would effect the single static variable.
         * There are two solutions to this, as stated in the comments you could simply tell the compiler to use the C++11 standards which allow this method of initialisation, or you can use the more common and compatible method with older compilers which is to initialise it in the constructor (as you are already doing for root), like so:
         * https://stackoverflow.com/questions/55677923/warning-non-static-data-member-initializers-only-available-with-std-c11-or
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

       /*
        * 2.类的enum类型成员不能static
        * You cannot define static enum in C++.  static can only be the variable of the enum, not the type itself!
        * static enum {A, B, C, D}; // error: a storage class can only be specified for objects and functions
        */

        cout << "======block start: const member initialize:" << endl;
        cout << "const static member init when def: "<< StringBad::canInitMember << endl;
        cout << "member init in defination with c++11: " << headline1.memberInitInDefination << endl; 
        cout << "======block end." << endl; 
        /*
        * 3. 类的static成员即可通过类名称::访问，也可通过类对象.访问
        */
        cout << "======block start: static member visit:" << endl;
        cout << "static member visit using ClassName::" << StringBad::num_strings << endl;
        cout << "static member visit using instance." << headline1.num_strings << endl;
        cout << "======block end." << endl;

        cout << "======block start: enum member visit:" << endl;
        /*
        * 4.类的enum类型成员定义与访问
        */
        cout << "class enum member headline1.XL:" << headline1.XL << endl;
        cout << "class enum member StringBad::XL:" << StringBad::XL << endl;

        /*
        * 5.类的enum类型成员变量的定义与访问
        */
        headline1.class_typed_enum_var1 = headline1.alpha;
        headline1.class_typed_enum_var2 = StringBad::beta;
        cout << "class enum member var headline1.class_typed_enum_var1:" << headline1.class_typed_enum_var1 << endl;
        cout << "class enum member var headline1.class_typed_enum_var2:" << headline1.class_typed_enum_var2 << endl;
        cout << "======block end." << endl;

        callme1(headline1);
        cout << "headline1: " << headline1 << endl;

        /**
         * 6.类对象headline2按值传递给函数
         * 函数会创建类对象的一个副本，因此函数结束时此副本会被销毁，析构函数被调用
         * 
        */
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;


        cout << "Initialize one object to another:" << endl;
        StringBad sailor = sports;
        cout << "Sailor: " << sailor << endl;
        cout << "Assign one object to another:" << endl;

        /**
        * ClassName xxx; 这样其实已经初始化了！！，调用默认的无参构造函数
        */
        StringBad knot;
        cout << "ClassName xxx; will call no parameter constructor." << endl;

        /*
        * 此处没有构造，只有拷贝，所以不调用拷贝构造函数
        */
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "Exiting the block." << endl;
        /**
         * 7.在构造函数中使用new来分配内存时，必须在相应的析构函数中使用delete来释放内存
         * StringBad:: ~StringBad() {
            cout << "\"" << str << "\" object deleted, ";
            --num_strings;
            cout << num_strings << " left \n";
            delete [] str;
        }
        */
    }
    cout << "End of main()\n";
    return 0;
};

void callme1(StringBad & rsb) {
    cout << "String passed by reference:\n";
    cout << "   \"" << rsb << "\"\n";
}

void callme2(StringBad sb) {
    cout << "String passed by value: \n";
    cout << "   \"" << sb << "\"\n"; 
}
