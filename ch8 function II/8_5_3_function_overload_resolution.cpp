#include <iostream>

/**
* 函数重载解析：
* 对于函数重载，函数模板，函数模板重载，c++需要一个策略，决定函数调用哪个定义
* 1.创建候选列表 (函数名称相同的函数和模板)
* 2.基于候选列表创建可行列表 (参数数目正确)
* 3. 确定最佳可行函数 （参数是否需要匹配）
    i 完全匹配 (无转换，或仅有无关紧要的转换)
        i.i 常规函数
        i.ii 具体化模板
        i.iii 常规模板

        额外原则1： 非const的指针和引用 > const的指针和引用
        额外原则2：对于模板，具体的优先 （模板的部分排序规则）
            更具体的定义： 需要的转换更少
    ii 提升转换 （不会丢失信息，精度，字节更多）
    iii 标准转换
    iv 用户自定义转换
* 若无最佳匹配，则编译error： ambiguous...
*/

/**
* 标准转换：
    整型提升
    整型转换
    浮点转换
    浮点转换和整型转换
    算术转换
    指针转换
    引用转换
    指向成员的指针转换
*/

/**
 无关紧要的转换
 Type -> Type &
 Type & ->type
 Type [] -> * Type
 Type -> const Type
 Type -> volatile type
 Type * -> const Type
 Type * -> volatile Type
 Type (argument list) -> Type (*) (argument list) 函数指针

*/

/**
* 手动调用模板
*/


template <typename T>
void ShowArray(T arr[], int n);

template <typename T>
void ShowArray(T * arr, int n);


template <class T>
T lesser (T a, T b) {
    return a < b ? a : b;
}

int lesser (int a, int b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;
}

template <typename T>
T helper(T a, int b);

template <typename T>
T helper(T a, double b);


struct debts{
    char name[50];
    double amount;
};


int main () {
    using namespace std;

    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] = {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0},
    };
    double * pd[3];

    for (int i = 0; i < 3; i++) {
        pd[i] = &mr_E[i].amount;
    }

    cout << "Listing Mr. E's counts of thins:" << endl;
    ShowArray(things, 6);
    cout << "Listing Mr. E's debts:" << endl;
    ShowArray(pd, 3);


    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    cout << lesser(m, n) << endl;
    cout << lesser(x, y) << endl;
    cout << lesser<>(m, n) << endl; // 手动选择模板函数
    cout << lesser<int>(x, y) << endl; // 显示实例化

    cout << "\n\nTest hoist convertion has a higher priority\n\n";

    helper(m, 'c'); // char 到int是提升转换，char到double是标准转换

    return 0; 
}

template <typename T>
void ShowArray(T arr[], int n) {
    using namespace std;
    cout << "Template A:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "    ";
    }
    cout << endl;
}

template <typename T>
void ShowArray(T * arr[], int n) {
    using namespace std;
    cout << "Template B:" << endl;
    for (int i = 0; i < n; i++) {
        cout << *arr[i] << "    ";
    }
    cout << endl;
}

template <typename T>
T helper(T a, int b) {
    using namespace std;
    cout << "Using template 1:" << endl;
    return a + b;
}

template <typename T>
T helper(T a, float b) {
    using namespace std;
    cout << "Using template 2:" << endl;
    return a + b;
}