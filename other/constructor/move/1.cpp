/*
本主题介绍如何为 C++ 类编写移动构造函数和移动赋值运算符。 
移动构造函数使右值对象拥有的资源无需复制即可移动到左值中。 有关移动语义的详细信息，请参阅右值引用声明符：&&。
*/

/*
若要实现移动语义，通常可以向类提供“移动构造函数”，或者提供移动赋值运算符 (operator=)。 
其源是右值的复制和赋值操作随后会自动利用移动语义。 
与默认复制构造函数不同，编译器不提供默认移动构造函数。 有关如何编写和使用移动构造函数详细信息，

*/

/*
size_t 类型定义在cstddef头文件中，该文件是C标准库的头文件stddef.h的C++版。它是一个与机器相关的unsigned类型，其大小足以保证存储内存中对象的大小。
*/

/*
std::copy
Copies the elements in the range [first,last) into the range beginning at result.
*/

/*
Rvalue 引用支持“移动语义”的实现，这可以显著提高应用程序的性能。 
利用移动语义，你可以编写将资源（如动态分配的内存）从一个对象转移到另一个对象的代码。 
移动语义很有效，因为它允许从临时对象（无法在程序中的其他位置引用）转移资源。
*/

#include "iostream"
#include <vector>
using namespace std;


// Move constructor.
class MemoryBlock
{
    public:
        explicit MemoryBlock(size_t length) : _length(length) , _data(new int[length]) {
            std::cout << "In MemoryBlock(size_t). length = " << _length << "." << std::endl;
        }
        ~MemoryBlock() {
            std::cout << "In ~MemoryBlock(). length = " << _length << ".";
            if (_data != nullptr) {
                std::cout << " Deleting resource." << std::endl;
                delete[] _data;
            }
        }
        MemoryBlock(const MemoryBlock& other) : _length(other._length) , _data(new int[other._length])
        {
            std::cout << "In MemoryBlock(const MemoryBlock&). length = " << other._length << ". Copying resource." << std::endl;
            std::copy(other._data, other._data + _length, _data);
        }
        // Move constructor.
        // 该方法采用一个对类类型的右值引用作为参数
        MemoryBlock(MemoryBlock&& other) noexcept : _data(nullptr) , _length(0) {
            std::cout << "In MemoryBlock(MemoryBlock&&). length = " << other._length << ". Moving resource." << std::endl;
            // Copy the data pointer and its length from the
            // source object.
            _data = other._data;
            _length = other._length;
            // Release the data pointer from the source object so that
            // the destructor does not free the memory multiple times.
            other._data = nullptr;
            other._length = 0;
        }
        MemoryBlock& operator=(const MemoryBlock& other) {
            std::cout << "In operator=(const MemoryBlock&). length = " << other._length << ". Copying resource." << std::endl;
            if (this != &other) {
                // Free the existing resource.
                delete[] _data;
                _length = other._length;
                _data = new int[_length];
                std::copy(other._data, other._data + _length, _data);
            }
            return *this;
        }
        size_t Length() const {
            return _length;
        }
    private:
        size_t _length; // The length of the resource.
        int* _data; // The resource.
};

int main()
{
   // Create a vector object and add a few elements to it.
   vector<MemoryBlock> v;
   v.push_back(MemoryBlock(25));
   cout << "-----" << endl;
   v.push_back(MemoryBlock(75));
   cout << "-----" << endl;
   v.insert(v.begin() + 1, MemoryBlock(50));
   cout << "-----" << endl;
}