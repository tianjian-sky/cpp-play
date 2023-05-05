#include "exception"
#include "iostream"
using namespace std;

/*
未捕获异常，程序首先调用terminate(),默认情况下，terminate()会调用abort()，可以改变这个默认行为
*/
void myQuit () {
    std::cout << "Terminate due to Uncaught exception"<< std::endl;
}
int main () {
    set_terminate(myQuit);
    throw;
};
