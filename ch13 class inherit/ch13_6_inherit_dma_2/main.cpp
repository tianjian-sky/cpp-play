#include <iostream>
#include "dma.h"
#include "lackDma.h"
#include "hasDma.h"

int main() {
    /*
    * strncpy 与strcpy的区别
    * 拷贝源字符串的n个字符到目标字符串
    * strncpy 不会在末尾增加\0    
    *  
    */

    /*
    * 子类的成员有通过new进行内存分配的：
    * 需要在子类的拷贝构造函数中正确地new相应的成员
    * 需要在子类的重载复制运算符中先delete 后 new相应的成员
    * 需要在子类的析构函数中delete相应的成员
    */

   /*
   *
   * 调用父类的重载复制运算符写法：
   * baseDMA::operator=(hs);
   * (baseDMA) *this = hs;
   * 
   */

    /*
    * 子类访问父类的友元：使用强制类型转换
    * os << (baseDMA) rs; // 一定要强转一下，否则会又匹配到自己
    * 
    */

    /*
    * 类的运算符函数，继承性，成员还是友元，能否默认生成，能否为虚函数，能否有返回类型各异
    */

    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lackDMA ballon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);

    cout << "Displaying baseDMA object: " << endl;
    cout << shirt << endl;
    cout << "Displaying lackDMA object: " << endl;
    cout << ballon << endl;
    cout << "Displaying hasDMA object: " << endl;
    cout << map << endl;


    cout << "-----II------" << endl;
    lackDMA ballon2(ballon);
    cout << "Result of lackDMA cpoy:" << endl;
    cout << ballon2 << endl;
    cout << "-----III------" << endl;
    hasDMA map2;
    map2 = map;
    cout << "Result of hasDMA assignment:" << endl;
    cout << map2 << endl;
    return 0;
}