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
    * 保护继承
    * 
    * 访问方式 public    protected   private
    * 类内部   yes         yes       yes(子类no)    
    * 对象     yes         no        no
    * 
    * 继承方式              public          protected       private
    * 父类public成员        public          protected       private
    * 父类protected成员     protected       protected       private
    * 父类private成员       x                x               x
    */

    /*
        * protected继承来的public东西都变成protected了，
        * 要在类外使用:
        * 1.实现一个公有方法去访问他们
        * 2.使用using，重新定义访问权限
        double max() const;
        double min() const;
        using std::valarray<double>::sum; // 因为要在类外访问，因此using也要定义在public下
    */

   /*
   * 公有继承是接口继承
   * 私有继承是实现继承，继承来的每样东西若要暴露都得重新实现.
   */

    /* 
    公有继承是接口继承，私有继承是实现继承，保护继承是莫名其妙。
    一般来说对象的封装就是，数据（成员变量）是私有的，接口（成员函数）是公开的。
    接口继承就是父类的接口，在子类中也是公开的。在任何父类可以使用的地方，都可以替换为子类。
    实现继承就是，大概就是要在子类中使用了父类的接口（不然你继承它干嘛？），但是又不想外部用跟父类一样的使用方法来使用子类。
    其实就是一般意义上的代码复用，可以用组合替代继承来优化设计。保护继承大约是为了父类和孙子类的实现继承吧
    链接：https://www.zhihu.com/question/36133278/answer/86716175
    */

    /* 私有继承vs包含？
    
    包含：
        简单，易于理解
        能包含多个同类的子对象。
        不能访问保护成员
        不能重新定义虚函数
    私有继承：
        不能包含同类的子对象多个。
        复杂(尤其是多继承)：
            多个父类的同名方法
            多个父类共享祖先
        能访问保护对象
        能重新定义虚函数
    */

   /*
    * 私有继承，访问未命名子对象的友元函数
    * 通过强制转型，访问
    */

  
    Student ada[pupils] = {
        Student(quizzes),
        Student(quizzes),
        Student(quizzes)
    };

    int i;

    for (i = 0; i < pupils; i++) {
        set(ada[i], quizzes);
    }
    cout << "\n Student List:" << endl;
    for (int i = 0; i < pupils; i++) {
        cout << ada[i].Name() << endl;
    }
    cout << "\nMax score:";
    for (int i = 0; i < pupils; i++) {
        cout << "Max score is: " << ada[i].max() << endl;
    }
    cout << "\nMin score:";
    for (int i = 0; i < pupils; i++) {
        cout << "Min score is: " << ada[i].min() << endl;
    }
    cout << "\nSum score:";
    for (int i = 0; i < pupils; i++) {
        cout << "Sum score is: " << ada[i].sum() << endl;
    }
    cout << "Done." << endl;
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