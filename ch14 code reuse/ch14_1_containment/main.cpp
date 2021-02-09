#include <iostream>
#include "studentc.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student &sa, int n);
const int pupils = 3;
const int quizzes = 5;

int main () {

    /*
    * typedef放在类的私有部分，只可以公有私有成员都可修饰，放在类的公有部分，只能修饰公有成员 (出现顺序？)
    */
    
    /*
    * 关闭隐式转换
    * 防止不小心写错出现这样的隐式转换
    * Student doh("Homer", 10);
    * homer = 5; // 本意是homer[6] = 5;
    */
    
    Student ada[pupils] = {
        Student(quizzes),
        Student(quizzes),
        Student(quizzes)
    };
    int i;
    for (int i = 0; i < pupils; i++) {
        set(ada[i], quizzes);
    }
    cout << "\n student List:\n";
    for (int i = 0; i < pupils; i++) {
        const Student & temp = ada[i];
        cout << temp.Name() << endl; // 对于常量引用调用成员方法，需要使用const成员函数, 否则编译期间报错
    }
    cout << "\nResults:\n";
    for (i = 0; i < pupils; i++) {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";
    return 0;
}

void set(Student &sa, int n) {
    cout << "Please enter the student's name:" ;
    getline(cin, sa);
    cout << "Please enter " << n << " quiz scores:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> sa[i];
    }
    while (cin.get() != '\n') {
        continue;
    }
}