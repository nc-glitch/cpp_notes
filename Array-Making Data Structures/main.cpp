#include <iostream>

#include <array>
#include <cstring>

template<typename T, size_t S>
class Array
{
public:
    constexpr size_t Size() const { return S; }

    // adding the index functionality
    // T must be a reference so it is an lvalue
    // size_t should be used over an int because ints can negative
    T& operator[](size_t index) { return m_Data[index]; }
    // adding a version for const Arrays
    const T& operator[](size_t index) const { return m_Data[index]; }

    // Adding pointer accesses
    T* Data() { return m_Data; }
    const T* Data() const { return m_Data; }
private:
    T m_Data[S];
    // could do int* instead, utilizing alloca in consutrctor
    // alloca can lead to compilation errors because its dynamicaly allocated in the STACK
};

int main() {


    int array[5]; // static array, allocated before running, better

    int size = 5;
    int* heapArray = new int[size]; // can take in integer arguments since run at execution time
    delete[] heapArray;

    std::array<int, 10> collection;
    collection.size();


    Array<int, 5> data;

    // using pointer data.Data(), sets each byte to 0 for a length of data.Size()
    memset(data.Data(), 0 , data.Size());

    for(size_t i = 0; i < data.Size(); i++)
        std::cout << data[i] << "\n";


    // Simply performs compile-time assertion checking
    static_assert(data.Size() < 10, "Size is too large!");

}
