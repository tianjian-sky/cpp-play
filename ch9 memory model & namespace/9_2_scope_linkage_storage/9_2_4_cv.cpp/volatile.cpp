#include <iostream>
const int Ar_size = 10;

void strcount(const char * str);

/**
 * volatile
 * volatile 关键字是一种类型修饰符，用它声明的类型变量表示可以被某些编译器未知的因素更改，
 * 比如：操作系统、硬件或者其它线程等。遇到这个关键字声明的变量，编译器对访问该变量的代码就不再进行优化，
 * 从而可以提供对特殊地址的稳定访问。
 * 当要求使用 volatile 声明的变量的值的时候，系统总是重新从它所在的内存读取数据，
 * 即使它前面的指令刚刚从该处读取过数据。而且读取的数据立刻被保存。
 * #include <stdio.h>
 
void main()
{
    int i = 10;
    int a = i;
 
    printf("i = %d", a);
 
    // 下面汇编语句的作用就是改变内存中 i 的值
    // 但是又不让编译器知道
    __asm {
        mov dword ptr [ebp-4], 20h
    }
 
    int b = i;
    printf("i = %d", b);
}

其实不只是内嵌汇编操纵栈"这种方式属于编译无法识别的变量改变，
另外更多的可能是多线程并发访问共享变量时，一个线程改变了变量的值，怎样让改变后的值对其它线程 visible。
一般说来，volatile用在如下的几个地方：
1) 中断服务程序中修改的供其它程序检测的变量需要加 volatile；
2) 多任务环境下各任务间共享的标志应该加 volatile；
3) 存储器映射的硬件寄存器通常也要加 volatile 说明，因为每次对它的读写都可能由不同意义；
**/
volatile int i=10;


int main () {
    int i = 10;
    int a = i;
 
    printf("i = %d", a);
 
    // 下面汇编语句的作用就是改变内存中 i 的值
    // 但是又不让编译器知道
    __asm {
        mov dword ptr [ebp-4], 20h
    }
 
    int b = i;
    printf("i = %d", b);
}

