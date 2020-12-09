#include <iostream>
#include <string>

struct free_throws {
    std::string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws &ft);
void set_pc(free_throws &ft);

// 1、传递结构体变量，值传递

free_throws & accumulate(free_throws &target, const free_throws &source); // 1.结构体引用

free_throws changeStruct0 (free_throws target); //传值 返回值

free_throws changeStruct (free_throws &target); //传引用 返回值

free_throws & changeStructReturnRef (free_throws &target); // 返回引用

const free_throws & changeStructReturnRef_const (free_throws &target);  // 返回常引用

/**
* 将引用作为参数传递
*/
int main () {
    free_throws one = {"Ifelsa Branch", 13, 14};
    free_throws two = {"Andor Knott", 10, 16};
    free_throws three = {"Minnie Max", 7, 9};
    free_throws four = {"Whily Looper", 5, 9};
    free_throws five = {"Long Long", 6, 14};
    free_throws team = {"Throwgoods", 0, 0};

    free_throws t0 = {"Hello", 999, 0};
    free_throws t1 = {"Hello", 0, 0};
    free_throws t2 = {"World", 0, 0};

    free_throws dup;

    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);

    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    display(team);

    dup = accumulate(team, five);
    std::cout << "Displaying team:" << std::endl;
    display(team);
    std::cout << "Displaying dup after assignment:" << std::endl;
    display(dup);
    set_pc(four);

    /*
    * accumulate（。。）为何可以是左值，因为他返回一个引用，是一个可修改的内存块。
    * four为何可以是右值
    */

    /*
    * 引用返回类型是左值
    * 非引用返回类型是右值，这种返回值位于临时内存单元中，下一条语句执行时就可能不存在
    */

    accumulate(dup, five) = four;
    std::cout << "Displaying dup after ill-advised assignment:" << std::endl;
    display(dup);


    // 1.传结构体的值给函数，实参拷贝，外部的结构体不受影响
    std::cout << "Pass struct value to funcion:" << std::endl;
    std::cout << "before change:" << std::endl;
    display(t0);
    changeStruct0(t0);
    std::cout << "after change:" << std::endl;
    display(t0);



    /**
    * 函数返回值拷贝问题
    *
    * 1.当函数返回值不是引用类型是，会发生复制，且接收函数返回值的变量不能是引用类型
    * 2.当函数返回值是引用类型:
    * 2.1 返回值是常引用，不复制
    * 2.2 返回值是普通引用
    * a) 接收函数返回值的变量是引用类型，不会发生复制
    * b) 接收函数返回值的变量不是引用类型时，会发生复制
    */

    /**
    * 为何要返回引用？
    * 函数返回值拷贝问题
    *
    * 当返回一个结构时，将把整个结构复制到一个临时位置，在将这个拷贝复制给变量
    * 当返回引用时，省去中间步骤，效率更高
    *
    */
    std::cout << "Test return value with/without ref:" << std::endl;

    std::cout << "1.return value without ref:" << std::endl;
    std::cout << "before change:" << std::endl;
    display(t1);
    std::cout << "sctuct address:" << &t1 << std::endl;
    free_throws t1_t = changeStruct(t1);
    std::cout << "after change:" << std::endl;
    display(t1);
    std::cout << "sctuct address:" << &t1_t << std::endl;

    std::cout << "2.return value with ref:" << std::endl;
    std::cout << "before change:" << std::endl;
    display(t2);
    std::cout << "sctuct address:" << &t2 << std::endl;
    free_throws t2_t = changeStructReturnRef(t2);
    free_throws &t2_ref = changeStructReturnRef(t2); 
    std::cout << "after change:" << std::endl;
    display(t2_t);
    std::cout << "sctuct address:" << &t2_t << std::endl;
    std::cout << "sctuct address (received by ref):" << &t2_ref << std::endl;


    std::cout << "3.return value with !!cosnt!! ref:" << std::endl;
    std::cout << "before change:" << std::endl;
    display(t2);
    std::cout << "sctuct address:" << &t2 << std::endl;
    free_throws t3_t = changeStructReturnRef_const(t2);
    const free_throws &t3_ref = changeStructReturnRef_const(t2); 
    std::cout << "after change:" << std::endl;
    display(t2_t);
    std::cout << "sctuct address:" << &t3_t << std::endl;
    std::cout << "sctuct address (received by ref):" << &t3_ref << std::endl;

    return 0; 
}

void display(const free_throws &ft) {
    using std::cout;
    using std::endl;
    cout << "Name:" << ft.name << endl;
    cout << " Made:" << ft.made << endl;
    cout << "Attempts:" << ft.attempts << endl;
    cout << "Percent:" << ft.percent << endl;

}
void set_pc(free_throws &ft) {
    if (ft.attempts != 0) {
        ft.percent = 100.0f * float(ft.made)/float(ft.attempts);
    } else {
        ft.percent = 0;
    }
}

free_throws &accumulate(free_throws &target, const free_throws &source) { // 返回引用
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;
}

free_throws changeStruct0 (free_throws target) {
    target.made += 1000;
    return target;
}

free_throws changeStruct (free_throws &target) {
    target.made += 1000;
    return target;
}

free_throws& changeStructReturnRef (free_throws &target) {
    target.made += 1000;
    return target;
}

const free_throws & changeStructReturnRef_const (free_throws &target) {
    target.made += 1000;
    return target;
}

