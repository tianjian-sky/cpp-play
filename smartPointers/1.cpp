/*
C++ 11 智能指针

在 C++11 标准中新增unique_ptr、shared_ptr和weak_ptr这三个智能指针来自动回收堆分配的对象。

new 申请的类在堆空间，用完需要 delete，

1.auto_ptr:
在 C++98 开始推出 auto_ptr 管理裸指针，让开发者不需要手动释放指针内存，当生命周期结束时自动释放内存。但是 auto_ptr 在转移所有权会出现野指针导致崩溃。
void autoPtr(){
    std::auto_ptr<int> auto_ptr1(new int (1));
    std::auto_ptr<int> auto_ptr2 = auto_ptr1;  // 转移控制权
    *auto_ptr1 += 1;   // 程序崩溃
    // 由于auto_ptr1转移给auto_ptr2，auto_ptr1变为空指针，导致程序崩溃，可以通过get方法先判空
    if (auto_ptr1.get()){ // 判空后执行
        // do somethings
    }
}
2.unique_ptr
C++11 新出现unique_ptr智能指针管理内存，从命名上可以知道，该智能指针智能被唯一一个对
象持有，与 auto_ptr 一样拥有唯一拥有控制权的特性，不同的是 unique_ptr 是没有复制构造函数的，只能通过显示std::move()方法转移控制权。

auto unique_ptr1 = std::unique_ptr<int>();
auto unique_ptr2 = unique_ptr1;  // 直接复制，错误。编译出错
auto unique_ptr3 = std::move(unique_ptr1); // unique_ptr1转移控制权到unique_ptr3，unique_ptr1变为nullptr

*/

/*
注解
此类模板描述指向已分配对象的智能指针（名为 auto_ptr）。 指针必须为 Null 或指定 new 所分配的对象。 如果 auto_ptr 的存储值已分配给其他对象，则它将转移所有权。 （它在与空指针进行转移后替换存储值。）auto_ptr<Type> 的析构函数将删除已分配的对象。 auto_ptr<Type> 可确保在块失去控制权时（甚至在已引发异常的情况下）自动删除已分配的对象。 不应构造两个拥有相同对象的 auto_ptr<Type> 对象。

可以将 auto_ptr<Type> 对象作为函数调用的参数按值传递。 auto_ptr 不能是任何标准库容器的元素。 你无法使用 C++ 标准库容器可靠地管理一系列 auto_ptr<Type> 对象。

unique_ptr 对象可以移动，但不能复制
*/
