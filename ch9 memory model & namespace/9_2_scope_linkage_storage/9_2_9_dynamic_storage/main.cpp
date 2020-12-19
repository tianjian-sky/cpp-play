#include <iostream>
#include <new>

const int BUF = 512;
const int N = 5;
char buffer[BUF];

/**
 * 动态内存：
 * new, delete
 * 前述的几种存储方案不适用于动态内存。
 * 如:
 * float *p = new float[20]
 * new 分配的80个字节将一直驻留在内存中，直到使用delete将其释放。
 * 但是，p适用于前面的存储方案。可以在其他文件中extern引入。
 * 
 * new int;
 * new int[n];
 * 
 * delete a;
 * delete [] b;
 * 
 * new 分配的地址在 heap 中
*/

/**
 * new 的底层实现
 * 
 * new int [4] {1,2,3,4} ---运算符重载--> new (4 * sizeof(int))
 * void * operator new(std::size_t); // used by new
 * void * operator new [] (std::size_t) // used by new[]
 * int *p3 = new (buffer) int [40] -> new(40 * sizeof(int), buffer)
 * 
*/ 

/**
 * 定位 new 运算符 ：分配内存同时可以让程序员指定内存的位置
 * new (placement) int;
 * new (placement) int [20];
 * * 其中placement相当于是一个地址，告诉new使用placement这个地址。
 * pd2 = new (addr + N * sizeof(double)) double[N]
 * 
 * 
*/ 

/*
* delete 只能用于常规new运算符分配的内存
*/

int main () {
    using namespace std;
    double *pd1, *pd2;
    int i;
    cout << "Calling new and replace new " << endl;
    pd1 = new double[N];
    pd2 = new (buffer) double[N]; // 定位new
    for (int i = 0; i < N; i++) {
        pd2[i] = pd1[i] = 1000 + 20.0*i;
    }
    cout << "Memory address:" << endl;
    cout << " heap: " << pd1 << endl;

    /**
     * void * 为"无类型指针"，针可以指向任意类型的数据
    */

    cout << " Static:" << (void *) buffer << endl;
    cout << " pd2:" << pd2 << endl; // pd2 and buffer 有相同的地址
    cout << "Memory contents:" << endl;
    for (int i = 0; i < N; i++) {
        cout << pd1[i] << " at " << "&pd1[i]" << "; ";
        cout << pd2[i] << " at " << "&pd2[i]" << endl;
    }

    cout << "\n Calling new and replace new a second time:" << endl;
    double *pd3, *pd4;
    pd3 = new double[N];
    pd4 = new (buffer) double[N]; // 定位new
    for (int i = 0; i < N; i++) {
        pd4[i] = pd3[i] = 1000 + 40.0*i;
    }
    cout << "Memory contents:" << endl;
    for (int i = 0; i < N; i++) {
        cout << pd3[i] << " at " << "&pd3[i]" << "; ";
        cout << pd4[i] << " at " << "&pd4[i]" << endl;
    }

    cout << "\n Calling new and replace new a third time:" << endl;
    delete [] pd1;

    /*
    * delete 只能用于常规new运算符分配的内存
    */
    // delete [] pd2;// runtime error!!

    pd1 = new double[N];
    pd2 = new (buffer + N * sizeof(double)) double[N]; // 定位new
    cout << "buffer address:" << (double *) buffer << endl;
    cout << "pd2 address" << pd2 << endl;
    cout << "pd2's address offset is :" << pd2 - (double *) buffer << endl;
    for (int i = 0; i < N; i++) {
        pd2[i] = pd1[i] = 1000 + 60.0*i;
    }
    cout << "Memory contents:" << endl;
    for (int i = 0; i < N; i++) {
        cout << pd1[i] << " at " << "&pd1[i]" << "; ";
        cout << pd2[i] << " at " << "&pd2[i]" << endl;
    }

    delete [] pd1;
    delete [] pd3;
    return 0;
}

