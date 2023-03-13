/*
从某个类删除 const、volatile 和 __unaligned 属性。

https://zhuanlan.zhihu.com/p/372320706


1.引用转换，去掉底层const
2. 指针转换，去掉底层const
3. 加上底层const
4. 类类型的const引用去除底层const
5. 类类型引用添加底层const
6. 类类型指针移除底层const
7. 类类型指针添加底层const


*/

#include <iostream>

int main()
{
    const int &raw_size = 52;
    int &size = const_cast<int &>(raw_size); // type = int&
    size = 1;
    std::cout << "size = " << size << ", raw_size = " << raw_size << std::endl;
    return 0;
}
// 输出:
// size = 1, raw_size = 1