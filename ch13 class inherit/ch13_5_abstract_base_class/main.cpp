#include <iostream>
#include "acctabc.h"
#include "brassPlus.h"
#include "string"

const int CLIENTS = 4;

int main () {
    using std::cin;
    using std::cout;
    using std::endl;

    /**
    * 指针数组与数组指针
    * A) int *p1[10];
    * B) int (*p2)[10];
    *A: “[]”的优先级比“*”要高。p1 先与“[]”结合，构成一个数组的定义，数组名为p1，int *修饰的是数组的内容，即数组的每个元素。那现在我们清楚，这是一个数组，其包含10 个指向int 类型数据的指针，即指针数组。
    *B:  至于p2 就更好理解了，在这里“（）”的优先级比“[]”高，“*”号和p2 构成一个指针的定义，指针变量名为p2，int 修饰的是数组的内容，即数组的每个元素。数组在这里并没有名字，是个匿名数组。
    */
    AcctABC * p_clients[CLIENTS];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    AcctABC abc("John Doe", 33333, 9999);

    /*
    * 纯虚函数
    * 纯虚函数是一种特殊的虚函数，在许多情况下，在基类中不能对虚函数给出有意义的实现，而把它声明为纯虚函数，它的实现留给该基类的派生类去做。这就是纯虚函数的作用。
    * 纯虚函数也可以叫抽象函数，一般来说它只有函数名、参数和返回值类型，不需要函数体。这意味着它没有函数的实现，需要让派生类去实现。
    * C++中的纯虚函数，一般在函数签名后使用=0作为此类函数的标志。Java、C#等语言中，则直接使用abstract作为关键字修饰这个函数签名，表示这是抽象函数(纯虚函数)。
    */

    /*
    * 抽象类
    * 包含纯虚函数的类称为抽象类。由于抽象类包含了没有定义的纯虚函数，所以不能定义抽象类的对象。
    */


    /*
    1、为了方便使用多态特性，我们常常需要在基类中定义虚函数。
    2、在很多情况下，基类本身生成对象是不合情理的。例如，动物作为一个基类可以派生出老虎、孔雀等子类，但动物本身生成对象明显不合常理。
    为了解决上述问题，引入了纯虚函数的概念，将函数定义为纯虚函数（方法：virtual ReturnType Function()= 0;）。若要使派生类为非抽象类，则编译器要求在派生类中，必须对纯虚函数予以重写以实现多态性。同时含有纯虚函数的类称为抽象类，它不能生成对象。这样就很好地解决了上述两个问题。
    */

    for (int i = 0; i < CLIENTS; i++) {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or 2 for BrassPlus account: ";
        while(cin >> kind && (kind != '1' && kind != '2')) {
            cout << "Enter either 1 or 2: " ;
        }
        if (kind == '1') {
            p_clients[i] = new Brass(temp, tempnum,tempbal);
        } else {
            double tmax, trate;
            cout << "Enter the overdraft limit:$";
            cin >> tmax;
            cout << "Enter the interest rate " << "as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
        } 
        while(cin.get() != '\n') {
            continue;
        }
    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++) {
        p_clients[i]->ViewAcct();
        cout << endl;
    }
    for (int i = 0; i < CLIENTS; i++) {
        delete p_clients[i];
    }
    cout << "Done." << endl;
    return 0;
}