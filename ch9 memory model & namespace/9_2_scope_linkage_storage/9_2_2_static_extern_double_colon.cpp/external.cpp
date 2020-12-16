#include <iostream>

using namespace std;

double warning = 0.3;

/**
 * ODR 单定义规则
 * 变量只能有一次定义
 * A文件定义的静态外部变量，B文件中只能用extern引用此变量，而不能重新定义
 * A文件定义的静态外部变量，B文件中则可用static定义同名的静态内部链接性变量，不算重复定义。
*/


/**
 * extern 此变量/函数是在别处定义的，要在此处引用
 * ::是作用域运算符，A::B表示作用域A中的名称B，A可以是名字空间、类、结构；
 */

/**
 * 存储方式：
 * 1）自动
 * 2）寄存器
 * 3）静态，无链接性: 代码块中，static修饰
 * 4）静态，外部链接性： 不在任何函数中，ertern接收
 * 5）静态，内部链接性：不在任何函数中，static修饰 
 * 
*/
void update(double dt);
void local();

int main () {
   
    cout << "Global warning is: " << warning << " degrees." << endl;
    update(0.1);
    cout << "Global warning is: " << warning << " degrees." << endl;
    local();
    cout << "Global warning is: " << warning << " degrees." << endl;
   return 0;
}