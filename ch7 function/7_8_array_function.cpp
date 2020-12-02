#include <iostream>
#include <array> //1. 模板类array ，c++11   g++ filename -std=c++11
#include <string>
const int Seasons = 4;

const std::array<std::string, Seasons> Snames = {"Spring", "Summer", "Fall", "Winter"}; //2.名称array位于std空间中



/**
c++中，类对象是基于结构的，结构编程的某些因素也适用于类

*/
void fill(std::array<double, Seasons> * pa);

// 按值将对象传递给函数，函数接收的是原始对象的副本
void show(std::array<double, Seasons> da);

int main () {
    std::array<double, Seasons> expenses;
    fill(&expenses);
    show(expenses);
    return 0;
}

void fill(std::array<double, Seasons> * pa){
    using namespace std;
    for (int i = 0; i < Seasons; i++) {
        cout << "Enter " << Snames[i] << " expenses:";
        cin >> (*pa)[i]; // 3. ??

        /**
        * 指针数组与数组指针
        * A) int *p1[10];
        * B) int (*p2)[10];
        *A: “[]”的优先级比“*”要高。p1 先与“[]”结合，构成一个数组的定义，数组名为p1，int *修饰的是数组的内容，即数组的每个元素。那现在我们清楚，这是一个数组，其包含10 个指向int 类型数据的指针，即指针数组。
        *B:  至于p2 就更好理解了，在这里“（）”的优先级比“[]”高，“*”号和p2 构成一个指针的定义，指针变量名为p2，int 修饰的是数组的内容，即数组的每个元素。数组在这里并没有名字，是个匿名数组。
        */
    }
}

void show(std::array<double, Seasons> da) {
    using namespace std;
    double total = 0.0;
    cout << "\nExpenses\n";
    for (int i = 0; i < Seasons; i++) {
        cout << "Enter " << Snames[i] << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $" << total << endl;
}




