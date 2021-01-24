#include <iostream>
#include <string>
#include <new>

using namespace std;
const int BUF = 512;

class JustTesting {
    private:
        string words;
        int number;
    public:
        JustTesting(const string & s = "Just Testing", int n = 0) {
            words = s;
            number = n;
            cout << words << " constructed" << endl;
        }
        ~JustTesting() {
            cout << words << " destroyed" << endl;
        }
        void Show () const {
            cout << words << ", " << number << endl;
        }
};

/**
 * 定位new：
 * 
 * 一般的new运算符负责在heap堆中找到一个足以能够满足要求的内存块。
 * 定位new运算符(placement new)，它能够在分配内存时指定内存的位置。
 * 
 *      不同与常规的new运算符，定位new运算符不需要相应的delete运算符来释放内存。因为它本身就不开辟新的内存。
 *      必须 #include <new>，否则报错：没有与参数列表匹配的重载 "operator new" 实例 -- 参数类型为:  (unsigned long, char *) 
 * 
 * https://zhuanlan.zhihu.com/p/52403511
 * 
 */


int main () {
    char * buffer = new char[BUF];
    JustTesting *pc1, *pc2;
    /**
     * 必须 #include <new>，否则报错：没有与参数列表匹配的重载 "operator new" 实例 -- 参数类型为:  (unsigned long, char *) 
     */
    pc1 = new (buffer) JustTesting;
    pc2 = new JustTesting("Heap1", 20);

    cout << "Mem block addr:" << endl << "buffer: " << (void *) buffer << "    heap: " << pc2 << endl;
    cout << "Memory contents:" << endl;
    cout << pc1 << ": ";
    pc1 -> Show();
    cout << pc2 << ": ";
    pc2 -> Show();

    JustTesting *pc3, *pc4;
    pc3 = new (buffer) JustTesting("Bad Idea", 6);
    pc4 = new JustTesting("Heap2", 10);

    cout << "Memory contents:" << endl;
    cout << pc3 << ": ";
    pc3 -> Show();
    cout << pc4 << ": ";
    pc4 -> Show();
    delete pc2;
    delete pc4;

    /**
     * 可不可以delete 定位new生成的指针？
     */
    // delete pc1; // ok

    /*
    * delete buffer 不会导致它实际存储的对象的析构函数调用，没那么高级,但是确实释放了地址
    */
    const int option = 2;
    if (option == 1) {
        // 方法1： delete [] buffer; 删除整块的地址
        // 缺点，类对象的析构函数不会调用
        delete [] buffer; // ok
    } else if (option == 2) {
        // 方法2：手动调用析构函数
        // 缺点：需要手动调用 ,且原始地址也需要delete
        pc3->~JustTesting();
        delete []buffer;
    }

    cout << "Done" << endl;
    return 0;
}