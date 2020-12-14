#include <iostream>
#include "./coordin.h"

using namespace std;

int global = 888; // static duraction, external linkage;
static int int_one = 999; // static duration, internal linkage;

/**
 * 存储方式：
 * 1）自动
 * 2）寄存器
 * 3）静态，无链接性: 代码块中，static修饰
 * 4）静态，外部链接性： 不在任何函数中，ertern接收
 * 5）静态，内部链接性：不在任何函数中，static修饰 
 * 
*/

void container () {
    static int s_no = 1; // 与自动变量不同，即使在函数未执行时，静态变量也留在内存中
    cout << "static duration, no linkage:" << s_no << endl;
    cout << "static duration, global linkage: " << global << endl;
    cout << "static duration, internal linkage: " << int_one << endl;
}

int main () {
   rect rplace;
   polar pplace;
   container();
   pplace = {100, 53};
   show_polar(pplace);
   // cout << s_no << endl; error: 's_no' was not declared in this scope
   
   return 0;
}