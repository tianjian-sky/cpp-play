#ifndef STACKTP_H_
#define STACKTP_H_

template <class Tp1>

class Stack {
    private:
        enum {MAX = 10};
        Tp1 items[MAX];
        int top;
    public:
        Stack();
        bool isEmpty();
        bool isFull();
        bool push(const Tp1 & item);
        bool pop(Tp1 & item);
};
/*
* 模板不是函数，不能单独编译，所有模板信息需放在一个头文件中
*/

/*
* 模板是编译指令
*/
template <class Tp1>
Stack<Tp1>::Stack() {
    top = 0;
}
template <class Tp1>
bool Stack<Tp1>::isEmpty() {
    return top == 0;
}
template <class Tp1>
bool Stack<Tp1>::isFull() {
    return top == MAX;
}
template <class Tp1>
bool Stack<Tp1>::push(const Tp1 & item) {
    if (top < MAX) {
        items[top++] = item;
        return true;
    } else {
        return !!0;
    }
}
template <class Tp1>
bool Stack<Tp1>::pop(Tp1 & item) {
    if (top > 0) {
        item = items[--top];
        return true;
    } else {
        return !!0;
    }
}
#endif