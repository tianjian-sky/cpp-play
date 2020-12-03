#include <iostream>


const double * f1 (const double ar[], int n);
const double * f2 (const double [], int);
const double * f3 (const double *, int);


/**
*
* 内联函数
*类似于宏展开，但是比宏展开好的地方是，inline发生在编译阶段，会做类型检查，消除了宏展开可能带来的语义隐患。
例如定义宏#define f(x, y) (x*y)就会在 f(x+1,y)的时候f(x,y)就变成了x+1*y，完全错误。用inline可以达到相同的意图，却不会产生错误。

作者：知乎用户
链接：https://www.zhihu.com/question/24185638/answer/26979839
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
inline double square (double x) {return x*x;}

int main () {
    using namespace std;
    
    double av[3] = {1112.3, 1542.6, 2227.9};

    /**
    *官方定义
    *if [some declaration] declares a variable, typedef [same declaration] would define a type.
    *
    */

    typedef double ddd;

    ddd d1 = 123.456;

    cout << "typedef var:" << d1 << endl;

    typedef const double *(*testFunc)(const double *, int);
    testFunc ff1 = f1;
    cout << "typedef var:" << *ff1(av, 2) << endl;
    ddd a,b;

    ddd c = 13.0;

    a = square(5.0);
    b = square(4.5 + 7.5);

    cout << "a=" << a << ",b=" << b << ",c=" << square(c++) << endl;

    return 0; 
}
const double * f1 (const double * ar, int n) {
    return ar;
}
const double * f2 (const double ar[], int n) {
    return ar + 1;
}
const double * f3 (const double ar[], int n) {
    return ar + 2;
}