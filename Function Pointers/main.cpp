#include <iostream>
#include <vector>

void HelloWorld(int a)
{
    std::cout << "Hello World! Value: " << a << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for(int value : values)
        func(value);
}

int main() {

    //points to the function's storage
    typedef void(*HelloWorldFunction)(int);
    HelloWorldFunction function = &HelloWorld;

    function(1); function(2); std::cout << std::endl;

    std::vector<int> values = { 1, 5, 4, 2, 3 };
    ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });
}
