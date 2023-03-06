/*
从某个类删除 const、volatile 和 __unaligned 属性。

https://zhuanlan.zhihu.com/p/372320706


1.引用转换，去掉底层const
2. 指针转换，去掉底层const
3. 加上底层const
4. 类类型的const引用去除底层const
5. 类类型引用添加底层const
6. 类类型指针移除底层const
7. 类类型指针添加底层const


*/
#include <iostream>

struct Item
{
public:
    Item(const int &value) : _value(value) {}

    void print() const
    {
        std::cout << "_value = " << _value << std::endl;
    }

    void set_value(const int32_t &value)
    {
        _value = value;
    }

private:
    int32_t _value{0};
};

int main()
{
    Item *item = new Item(32);
    item->print();
    item->set_value(0);
    const Item *it = const_cast<const Item *>(item);
    // const Item* it = static_cast<Item*>(item);
    // const Item* it = reinterpret_cast<Item*>(item);
    // const Item* it = dynamic_cast<Item*>(item);
    // it->set_value(0); // const转化之后，不可以进行写操作
    it->print();
    item->print();

    return 0;
}
