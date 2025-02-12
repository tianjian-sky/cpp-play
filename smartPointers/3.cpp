/*
weak_ptr

这个类模板描述了一个指向由一个或多个 shared_ptr 对象管理的资源的对象。 指向某个资源的 weak_ptr 对象不会影响该资源的引用计数。 当最后一个管理该资源 shared_ptr 的对象被销毁时，则即使存在指向该资源的 weak_ptr 对象，该资源也将被释放。 此行为对于避免数据结构中的循环至关重要。

在以下情况下 weak_ptr 对象将指向某个资源：如果该对象是从拥有该资源的 shared_ptr 对象构造而成；如果是从指向该资源的 weak_ptr 对象构造而成；或者使用 operator= 将该资源分配到了该对象。 weak_ptr 对象不提供直接访问其所指向的资源的权限。 需要使用该资源的代码可通过一个 shared_ptr 对象来执行该操作，该对象通过调用成员函数 lock 创建并拥有该资源。 weak_ptr 对象在其所指向的资源被释放时已过期，因为所有拥有该资源的 shared_ptr 对象已被销毁。 调用已过期的 weak_ptr 对象上的 lock 将创建一个空 shared_ptr 对象。

当两个或多个由 shared_ptr 对象控制的资源保留有相互引用的 shared_ptr 对象时，会发生循环。 例如，具有三个元素的循环的链接列表有一个头节点 N0；该节点保留有一个拥有下一个节点 N1 的 shared_ptr 对象；该节点保留有一个拥有下一个节点 N2 的 shared_ptr 对象；反过来，该节点保留有一个拥有头节点 N0 的 shared_ptr 对象，由此形成闭合循环。 在这种情况下，引用计数从不变为零，并且从不释放循环中的节点。 若要消除循环，最后一个节点 N2 应保留指向 N0 的 weak_ptr 对象，而不是 shared_ptr 对象。 由于 weak_ptr 对象不拥有 N0，因此不会影响 N0 的引用计数，并且销毁该程序对头节点的最后一个引用时，也将销毁列表中的节点。
*/