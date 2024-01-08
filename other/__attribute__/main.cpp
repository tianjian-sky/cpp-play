

#include <iostream>

using namespace std;

/**
 * 来了解一下GNU C __attribute__机制
 * https://zhuanlan.zhihu.com/p/474790212
 * 
 * __attribute__实际上是GCC的一种编译器命令，用来指示编译器执行实现某些高级操作。
 * __attribute__可以设置函数属性（Function Attribute）、变量属性（Variable Attribute）和类型属性（Type Attribute）。
 * LLVM也借用了GCC的__attribute__，并进行了扩展。
*/

// packed
// 让编译器在编译时取消结构体的字节优化对齐，按照实际占用的字节数进行对齐。

// aligned
// 规定变量或结构体成员最小对齐格式，以字节为单位。让用户自行决定变量的对齐字节数，比如一些处理器架构要求向量表需要按照规定的对齐地址放置，这时用户就需要进行控制了。

// section
// section控制变量或函数在编译时的段名。在嵌入式软件开发时用的非常多，比如有外扩Flash或RAM时，需要将变量或函数放置到外扩存储空间，可以在链接脚本中指定段名来操作。在使用MPU(存储保护)的MCU编程时，需要对存储器划分区域，将变量或代码放置到对应的区域，通常也是通过段操作来实现。
// 'section' attribute only applies to functions, global variables, Objective-C methods, and Objective-C properties
// 'section' attribute is not valid for this target: mach-o section specifier requires a segment and section separated by a comma



struct unpacked_str {
    uint8_t x;
    uint16_t y;

};
struct packed_str {
    uint8_t x;
    uint16_t y;
};

struct unpacked_str_packed {
    uint8_t x;
    uint16_t y;
}__attribute__((packed));
struct packed_str_packed {
    uint8_t x;
    uint16_t y;

}__attribute__((packed));

struct unpacked_str_aligned_8 {
    uint8_t x;
    uint16_t y;

}__attribute__((aligned(8)));
struct packed_str_aligned_8 {
    uint8_t x;
    uint16_t y;
}__attribute__((aligned(8)));


struct unpacked_str strupkd;
struct packed_str strpkd;
struct unpacked_str_packed strupkd_packed;
struct packed_str_packed strpkd_packed;
struct unpacked_str_aligned_8 strupkd_packed_aligned_8;
struct packed_str_aligned_8 strpkd_packed_aligned_8;

// const int identifier[3] __attribute__((section ("ident"))) = { 1,2,3 };

int main(void) {
    cout << "第一个结构体大小:" << sizeof(strupkd) << endl;
    cout << "第二个结构体大小:" << sizeof(strpkd) << endl;
    cout << "第一个结构体packed大小:" << sizeof(strupkd_packed) << endl;
    cout << "第二个结构体packed大小:" << sizeof(strpkd_packed) << endl;
    cout << "第一个结构体aligned(8)大小:" << sizeof(strupkd_packed_aligned_8) << endl;
    cout << "第二个结构体aligned(8)大小:" << sizeof(strpkd_packed_aligned_8) << endl;
    // cout << "访问指定section的变量:" << identifier[0] << endl;
}