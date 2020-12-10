#include <iostream>



int main () {
    using namespace std;

    int rats = 101;
    int &rodents = rats;
    const int &rodents_const = rats;

    cout << "rats = " << rats << endl;
    cout << "rodents = " << rodents << endl;
    cout << "rats address = " << &rats << endl;
    cout << "rodents address = " << &rodents << endl;


    /*
    * 引用作为右值赋值，看看新变量的地址
    */
    int temp = rodents; // 引用赋值给常规变量，常规变量地址是新的
    const int temp_const = rodents; // 引用赋值给const变量，const 变量地址是新的
    int & temp_ref = rodents; // 引用赋值给引用变量，引用变量地址就是引用的地址 (别名的别名)
    const int & temp_ref_const = rodents; // 引用赋值给常引用变量，常引用变量地址就是引用的地址 (别名的别名)

    cout << "\n1. rvalue is non-const ref\n" << endl;
    cout << "temp address = " << &temp << endl;
    cout << "const temp_const address = " << &temp_const << endl;
    cout << "ref temp_ref address = " << &temp_ref << endl;
    cout << "ref const temp_ref_const address = " << &temp_ref_const << endl;

    int temp_c = rodents_const; // 常引用赋值给常规变量，常规变量地址是新的
    const int temp_c_const = rodents_const; // 常引用赋值给const变量，const 变量地址是新的
    //int & temp_c_ref = rodents_const; // error： 普通引用不能接收常引用
    const int & temp_c_ref_const = rodents_const; // 常引用赋值给常引用变量，常引用变量地址就是引用的地址 (别名的别名)
    cout << "\n2. rvalue is const ref\n" << endl;
    cout << "temp_c address = " << &temp_c << endl;
    cout << "const temp_c_const address = " << &temp_c_const << endl;
    cout << "ref const temp_c_ref_const address = " << &temp_c_ref_const << endl;

    /**
    * 引用变量初始化后相当于建立绑定关系，以后再赋值不会影响他们的绑定关系了
    */

    /**
    * 引用变量的地址不能变，值可以变, 相当于是一个 type * const ...
    * int & robents = rats;
    * 相当于
    * int * const pr = &rats;
    * robents = *pr;
    */
    
    int bunnies = 50;

    rodents = bunnies; // 引用变量初始化为rat的引用，因此相当于对rat进行赋值

    cout << "bunnies = " << bunnies << endl;
    cout << "rats = " << rats << endl;
    cout << "rodents =" << rodents << endl;

    cout << "bunnies address = " << &bunnies << endl;
    cout << "rodents address = " << &rodents << endl; 

    /**
    * 引用变量初始化相当于建立绑定关系，以后再赋值不会影响他们的绑定关系了
    */

    bunnies = 0; // 这里改变的是bunnies，rat和他的引用不受影响

    cout << "bunnies = " << bunnies << endl;
    cout << "rats = " << rats << endl;
    cout << "rodents =" << rodents << endl;

    cout << "bunnies address = " << &bunnies << endl;
    cout << "rodents address = " << &rodents << endl; 


    int cat = 1;
    int *pt = &cat;
    int **ppt = &pt; // 指针的指针必须声明为**
    
    cout << "var address:" << &cat << endl;
    cout << "pointer value" << pt << endl;
    cout << "pointer address (&pt)" << &pt << endl;
    cout << "**pt value" << ppt << endl;
    /*
    * 引用变量初始化为某个指针的解除引用后的值，此时此引用变量指向指针变量所指向的变量
    * 将会沿着指针链条不断地向上追溯，一直找到根指针指向的变量，与其进行绑定
    */
    
    int &animal = **ppt; 
    
    int dog = 99;
    pt = &dog;  // 改变的是pt

    cout << "cat:" << cat << endl;
    cout << "dog:" << dog << endl;
    cout << "pt:" << *pt << endl;
    cout << "animal:" << animal << endl;
    cout << "cat address:" << &cat << endl;
    cout << "dog address:" << &dog << endl;
    cout << "pt value:" << pt << endl;
    cout << "animal address:" << &animal << endl;

    int apple = 1;
    int *pt2 = &apple;

    /**
    * 引用变量也要严格区分类型，如果引用的是一个指针，则前面要加*
    */
    // int &fruit = pt2; // error: invalid conversion from 'int*' to 'int'
    
    int* &fruit = pt2; // 这样fruit就会跟着变，此时引用变量初始化为未解除引用的值


    int banana = 99;
    pt2 = &banana;  // 改变的是pt

    cout << "apple:" << apple << endl;
    cout << "banana:" << banana << endl;
    cout << "pt2:" << *pt2 << endl;
    cout << "&fruit:" << *fruit << endl;
    cout << "apple address:" << &apple << endl;
    cout << "banana address:" << &banana << endl;
    cout << "pt2 value:" << pt2 << endl;
    cout << "fruit address:" << fruit << endl;

    /**
    * 常量引用 ，避免对引用赋值导致修改被引用的变量
    */

    int house = 999;
    int bigHouse = 1099;
    const &c_ref = house;

    // c_ref = bigHouse; // error: assignment of read-only reference 'c_ref'

    return 0; 
}
