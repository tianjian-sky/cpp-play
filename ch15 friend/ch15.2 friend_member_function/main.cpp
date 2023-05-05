#include <iostream>
#include "./tv.h"

/*
2.友元成员函数
仅让特定的类成员成为另一个类的友元
*/

/*
前向声明是为了
1. 避免头文件循环引用
2. 避免引入头文件
*/

int main() {
    using namespace std;
    Tv s42;
    cout << "Init settings for 42 Tv " << endl;
    s42.volup();
    s42.settings();
    s42.onoff();
    s42.chanup();

    Remote grey;
    grey.set_chan(s42, 10);
    grey.volup(s42);
    s42.settings();

}