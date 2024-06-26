

#include <iostream>
#include <string>

using namespace std;

/**
 * 结构体构造函数
 * 结构体数组
 * 初始化列表传函数指针
*/

/**
 * C++ 中函数指针的声明
 * return_type (*pointer_name)(argument_type1, argument_type2, ...);
 * 
 *  int (*fptr1)(int, int) { &add1 };
*/

struct node{
    int data;
    string str;
    char x;
    //注意构造函数最后这里没有分号哦！
    node() :x(), str(), data(){} //无参数的构造函数数组初始化时调用
    node(int a, string b, char c) :data(a), str(b), x(c){}//有参构造
};
//结构体数组声明和定义
struct node2{
    int data;
    string str;
    char x;
    node2() :x(), str(), data(){} //无参数的构造函数数组初始化时调用
    node2(int a, string b, char c) :data(a), str(b), x(c){}//初始化列表进行有参构造
}N[10];

struct InitFunc {
  InitFunc(void (*init_func)()) : init_func(init_func) {
    // This the function immediately upon constructions, and also register
    // it so that it can be called again on each worker that starts.
    cout << "cons begin" << endl;
    init_func();
  }
  void (*init_func)();
  InitFunc* next = nullptr;
};


void add () {
    cout << "function invoke" << endl;
}


int main(void) {
    node n1(1, "ac", 'b');
    cout << n1.data << ":" << n1.str << ":" << n1.x << endl;
    N[0] = node2(33, "ac", 'b');
    cout << N[0].data << ":" << N[0].str << ":" << N[0].x << endl;
    InitFunc i1(add);
}