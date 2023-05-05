/*

允许将任何指针转换为任何其他指针类型。 也允许将任何整数类型转换为任何指针类型以及反向转换。

reinterpret_cast 运算符可用于 char* 到 int* 或 One_class* 到 Unrelated_class* 之类的转换，这本身并不安全。

reinterpret_cast 的结果不能安全地用于除强制转换回其原始类型以外的任何用途。 在最好的情况下，其他用途也是不可移植的。

reinterpret_cast 运算符无法强制转换掉 const、volatile 或 __unaligned 特性。 有关移除这些特性的详细信息，请参阅 const_cast Operator。

reinterpret_cast 运算符将空指针值转换为目标类型的空指针值。

reinterpret_cast 的一个实际用途是在哈希函数中，即，通过让两个不同的值几乎不以相同的索引结尾的方式将值映射到索引。


*/

/*
依赖底层的实现，不可移植
不支持任意的转换
*/
#include <iostream>
using namespace std;

// Returns a hash code based on an address
unsigned short Hash(void *p)
{
    unsigned int val = reinterpret_cast<unsigned int>(p);
    return (unsigned short)(val ^ (val >> 16));
}

using namespace std;
int main()
{
    int a[20];
    for (int i = 0; i < 20; i++)
        cout << Hash(a + i) << endl;

    int num = 0x00636261; // 用16进制表示32位int，0x61是字符'a'的ASCII码
    int *pnum = &num;
    char *pstr = reinterpret_cast<char *>(pnum);
    cout << "pnum指针的值: " << pnum << endl;
    cout << "pstr指针的值: " << static_cast<void *>(pstr) << endl; // 直接输出pstr会输出其指向的字符串，这里的类型转换是为了保证输出pstr的值
    cout << "pnum指向的内容: " << hex << *pnum << endl;
    cout << "pstr指向的内容: " << pstr << endl;
    return 0;
}
// Output : 64641 64645 64889 64893 64881 64885 64873 64877 64865 64869 64857 64861 64849 64853 64841 64845 64833 64837 64825 64829