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
void divide(int a, int b) {
    if (b != 0) {
        std:: cout <<(float) a/b << std::endl;
    } else {
        std::abort();
    }
}

int main() {
    divide(2, 3);
    divide(3, 0);
    std:: cout << "end" << std::endl;
}