#include <iostream>

/**
 * 
 * 名称空间：
 * * 可以嵌套
 * * 不可以在代码块中
 * 全局名称空间：对应文件级的声明区域。全局变量都在里面
 * 名称空间是开放的，可以把名称加入到已经有的名称空间里
 * 名称空间里可以同时包含函数的原型及定义
 * 使用::访问得顶名称空间中的名称。
 *  * 未被限定的名称 
 *  * 限定的名称 xxx::aaa
*/

/**
 * using
 * using 声明：使特定标识符可用
 * using 编译指令：使整个名称空间可用
 * 
*/

/**
 * 命名空间的开放性：
 * 即可以随时把新的成员名称加入到已有的命名空间之中去。
*/

/**
 * 
 * 使用using编译指令导入一个已经声明的名称时，则局部名称将隐藏名称空间名
 * 局部名称优先级高于局部名称空间的名称
 * 
*/ 

/**
 * c++ 提倡将标准函数库放在std下
 * 
*/

namespace Jill {
    using namespace std;
    double bucket(double n);
    double fetch;
    struct Hill {
        int age;
        char name[50];
    };

    double bucket(double n) {
        cout << "Jill::bucket(n): " << n << endl;
        return n;
    }
}

void other();
char fetch;

int main () {
    using namespace std;
    using Jill::fetch; // put fetch into local namespace
    // double fetch; // error: redeclaration
    fetch = 1;
    ::fetch = 92;

    cout << "Jill fetch:" << fetch << endl;
    cout << "Global fetch:" << ::fetch << endl;


    return 0;
}
