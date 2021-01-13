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
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;

        /**
         * 类对象headline2按值传递给函数
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
         * Strintbad a = new Stringbad("abc")
         */
        // StringBad knot;
        // knot = headline1;
        // cout << "knot: " << knot << endl;
        // cout << "Exiting the block." << endl;
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
