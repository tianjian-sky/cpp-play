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


    using std::cout;
    using std::endl;

    
    return 0;
}