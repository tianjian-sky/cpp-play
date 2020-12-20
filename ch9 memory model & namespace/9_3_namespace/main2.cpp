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
 * using 声明：使名称空间中一个名称可用
 * using 编译指令：使名称空间中所有名称可用
 * 
*/

namespace Jill {
    using namespace std; // using 编译指令：使整个名称空间可用
    double bucket(double n);
    double fetch = 1;
    struct Hill {
        int age;
        char name[50];
    };

    double bucket(double n) {
        cout << "Jill::bucket(n): " << n << endl;
        return n;
    }
}

namespace Bill {
    using namespace std; // using 编译指令：使整个名称空间可用
    double bucket(double n);
    double fetch = 2;
    struct BillHill {
        int age;
        char name[50];
    };

    double bucket(double n) {
        cout << "Bill::bucket(n): " << n << endl;
        return n;
    }
}

char fetch = 'a';

int main () {
    // 1.
    //double fetch = 99; // 此处fetch 不与Jill fetch冲突
    using namespace std;
    using namespace Jill;
    Hill Thrill;

    double water = bucket(2);

    /**
     * 
     * 使用using编译指令导入一个已经声明的名称时，则局部名称将隐藏名称空间名
     * 局部名称优先级高于局部名称空间的名称
     * 
    */ 

    /**
     * using声明 好于 using编译指令
    */
   
    
    // 2.
    double fetch = 99; // 此处fetch 不与Jill fetch冲突

    

    cout << "fetch:" << fetch << endl;
    cout << "::fetch:" << ::fetch << endl;
    cout << "Jill::fetch:" << Jill::fetch << endl;

    return 0;
}
