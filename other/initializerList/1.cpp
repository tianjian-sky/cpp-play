/*
c++11
initializer_list 构造函数
initializer_list 类表示可以在构造函数和其他上下文中使用的指定类型的对象的列表。 您可通过使用大括号初始化构造 initializer_list：
使用初始化语法初始化stl容器
*/

#include <string>
#include <initializer_list>
using namespace std;

int main () {
    initializer_list<int> ilist1{ 5, 6, 7 };
    initializer_list<int> ilist2( ilist1 );
    if (ilist1.begin() == ilist2.begin())
        cout << "yes" << endl; // expect "yes"
}
