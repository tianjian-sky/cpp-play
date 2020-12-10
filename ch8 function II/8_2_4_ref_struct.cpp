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
    * 为何要返回引用？
        C++之中函数的返回分为以下几种情况：
	    1）main的返回值：返回0表示运行成功。
	    2）返回非引用类型：函数的返回值用于初始化在跳出函数时候创建的临时对象。用函数返回值来初始化临时对象与用实参初始化形参的方法是一样的。如果返回类型不是引用的话，在函数返回的地方，会将返回值复制给临时对象。且其返回值既可以是局部对象，也可以是表达式的结果。
	    3）返回引用：当函数返回引用类型的时候，没有复制返回值，而是返回对象的引用（即对象本身）。
        函数返回引用：实际上是一个变量的内存地址，既然是内存地址的话，那么肯定可以读写该地址所对应的内存区域的值，即就是“左值”，可以出现在赋值语句的左边。
	    1）函数返回引用的时候，可以利用全局变量（作为函数返回），或者在函数的形参表中有引用或者指针（作为函数返回），这两者有一个共同点，就是返回执行完毕以后，变量依然存在，那么返回的引用才有意义。
    *
    */

    /**
    * 引用变量作为rvalue赋值，lvalue的地址是否与rvalue相同，详见8_2_1
    */


    std::cout << "\n\nTest return value with/without ref:" << std::endl;

    std::cout << "1.return value without ref:" << std::endl;
    std::cout << "before change:" << std::endl;
    display(t1);
    std::cout << "sctuct address:" << &t1 << std::endl;
    free_throws t1_t = changeStruct(t1);
    std::cout << "after change:" << std::endl;
    display(t1);
    std::cout << "sctuct address:" << &t1_t << std::endl;

    std::cout << "\n\n2.return value with ref:" << std::endl;
    std::cout << "before change:" << std::endl;
    display(t2);
    std::cout << "sctuct address:" << &t2 << std::endl;
    free_throws t2_t = changeStructReturnRef(t2);
    free_throws &t2_ref = changeStructReturnRef(t2); 
    std::cout << "after change:" << std::endl;
    display(t2_t);
    std::cout << "sctuct address:" << &t2_t << std::endl;
    std::cout << "sctuct address (received by ref):" << &t2_ref << std::endl;


    std::cout << "\n\n3.return value with !!cosnt!! ref:" << std::endl;
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

