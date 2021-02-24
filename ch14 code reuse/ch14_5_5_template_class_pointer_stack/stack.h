#ifndef STK_H_
#define STK_H_

template <class tp>
class Stack {
    private:
        enum {SIZE=10};
        int stackSize;
        tp * items;
        int top;
    public:
        explicit Stack(int ss = SIZE); // 防止隐式转型


        /**
         * 在C++中，下面三种对象需要调用拷贝构造函数（有时也称“复制构造函数”）：
            1) 一个对象作为函数参数，以值传递的方式传入函数体；
            2) 一个对象作为函数返回值，以值传递的方式从函数返回；
            3) 一个对象用于给另外一个对象进行初始化（常称为赋值初始化）；
            如果在前两种情况不使用拷贝构造函数的时候，就会导致一个指针指向已经被删除的内存空间。对于第三种情况来说，初始化和赋值的不同含义是拷贝构造函数调用的原因。事实上，拷贝构造函数是由普通构造函数和赋值操作符共同实现的。描述拷贝构造函数和赋值运算符的异同的参考资料有很多。
        */

        /*
        * 对于有些场景，比如带隐式转换创建临时对象再拷贝构造，
        * 编译优化可以跳过拷贝构造，但是必须验证拷贝构造存在并且可用。
        * However, even if the compiler omits the call to the copy/move constructor, 
        * thecopy/move constructor must exist and must be accessible (e.g., not private) at thatpoint in the program.
        * https://www.zhihu.com/question/49068866
        * 
        *  Stonewt incognito = (Stonewt) (double)275;
        * 
        * 如果此时将复制构造函数移动到private中，则编译报错：
        *  error: 'Stonewt::Stonewt(const Stonewt&)' is private
        *  error: within this context Stonewt incognito = (Stonewt) (double)275; 
        */

        Stack(const Stack & st); // 拷贝构造函数
        ~Stack() {delete [] items;}
        bool isempty() { return top == 0; }
        bool isfull() { return top == stackSize;}
        bool push(const tp & item);
        bool pop(tp & item);
        Stack & operator=(const Stack &st); // 重载赋值运算符
};

template <class tp>
Stack<tp>::Stack(int ss) : stackSize(ss), top(0) {
    /*
    * 动态联编，动态数组：
    * 在运行阶段创建数组。
    * int *pt = new int [10]; // 创建一个10个int元素的数组，首地址赋值给int类型指针pt
    * 
    */
    items = new tp[stackSize];
}
template <class tp>
Stack<tp>::Stack(const Stack<tp> & st) {
    stackSize = st.stackSize;
    top = st.top;
    items = new tp[stackSize];
    for (int i = 0; i < top; i++) {
        items[i] = st.items[i];
    }
}
template <class tp>
bool Stack<tp>::push(const tp & item) {
    if (top < stackSize) {
        items[top++] = item;
        return true;
    } else {
        return false;
    }
}
template <class tp>
bool Stack<tp>::pop(tp & item) {
    if (top > 0) {
        item = items[--top];
        return true;
    } else {
        return false;
    }
}
template <class tp>
Stack<tp> & Stack<tp>::operator=(const Stack &st) {
    if (this == &st) {
        return *this;
    }
    delete [] items;
    stackSize = st.stackSize;
    top = st.top;
    items = new tp[stackSize];
    for (int i = 0; i < top; i++) {
        items[i] = st.items[i];
    }
    return *this;
}


#endif