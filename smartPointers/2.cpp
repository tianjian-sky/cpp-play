/*
C++ 11 智能指针

在 C++11 标准中新增unique_ptr、shared_ptr和weak_ptr这三个智能指针来自动回收堆分配的对象。

new 申请的类在堆空间，用完需要 delete，

3.shared_ptr
相对比unique_ptr，shared_ptr支持复制，即多个对象共享同一块内存。采用引用计数的方式式实现内存的自动管理，当复制一次值 + 1，释放一次则值 - 1，直到值为 0 内存会被回收

    3.1 std::make_shared
    Allocates and constructs an object of type T passing args to its constructor, and returns an object of type shared_ptr<T> that owns and stores a pointer to it (with a use count of 1).
    This function uses ::new to allocate storage for the object. A similar function, allocate_shared, accepts an allocator as argument and uses it to allocate the storage.

*/

/*
shared_ptr 类描述使用引用计数来管理资源的对象。 shared_ptr 对象有效保留一个指向其拥有的资源的指针或保留一个 null 指针。 资源可由多个 shared_ptr 对象拥有；当拥有特定资源的最后一个 shared_ptr 对象被销毁后，资源将释放。

在重新分配或重置资源后，shared_ptr 将停止拥有该资源。

*/

/*
一个 shared_ptr 对象拥有一个资源：
* 如果已使用指向该资源的指针构造它，
* 如果已从拥有该资源的 shared_ptr 对象构造它，
* 如果已从指向该资源的 weak_ptr 对象构造它，或
* 如果已使用 shared_ptr::operator= 或通过调用成员函数 shared_ptr::reset 将该资源的所有权分配给它。

*/

/*
拥有资源的 shared_ptr 对象共享控制块。 控制块包含：

拥有该资源的 shared_ptr 对象的数目，

指向该资源的 weak_ptr 对象的数目；

该资源的删除器（如果有），

控制块的自定义分配器（如果有）。
*/

/*
make_shared
使用make_shared作为创建对象的简单、更高效的方法，以及一个shared_ptr来同时管理对对象的共享访问。 在语义上，这两个语句是等效的：

auto sp = std::shared_ptr<Example>(new Example(argument));
auto msp = std::make_shared<Example>(argument);

*/