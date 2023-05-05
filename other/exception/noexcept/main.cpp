#include <iostream>
#include <cstdlib>

/*
异常处理
1. std::abort() 位于cstdlib
2. try-catch
3. noexcept 关键词
    告诉编译器，函数中不会发生异常，有利于编译器优化代码。若发生了异常，会调用std::terminate()
4. noexcept(常量表达式) 如果表达式不发生异常，则函数一定不发生异常
*/

class MyException {
    public:
        MyException (const char * s): msg(s) {}
        const char* msg;
};
int add (int a, int b) noexcept {
    return a + b;
}
float divide(int a, int b) noexcept {
        // char * msg = "devide zero error"; // 这在C++11标准中是错误的，会认为“xiao ming”是字符常量，定义一个指针去指向它，这样是有问题的，正确的定义方式是：
       if (b == 0) {
            const char * msg = "devide zero error";
            return a/b;
            // throw MyException(msg); // add' has a non-throwing exception specification but can still throw
       } else {
        return a / b; 
       }
}
int main() {
        divide(2, 3);
        divide(3, 0);
        add(1,2);
    std:: cout << "end" << std::endl;
}