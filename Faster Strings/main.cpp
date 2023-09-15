#include <iostream>
#include <string>
#include <string_view>

static uint32_t s_AllocCount = 0;

void* operator new(size_t size)
{
    s_AllocCount++;
    std::cout << "Allocating " << size << " bytes\n";

    return malloc(size);
}

void PrintName(const std::string_view name)
{
    std::cout << name << std::endl;
}



int main() {

    // Issues with strings: they utilize memory: the HEAP (SLOW)
    // only if string exceeds 32 bytes though (hypothetically)
    // code doesn't work: not 100% sure why though

    //const char* are the fastest though

    std::string name = "Yan Chernikov";
    const char* namechar = "Yan Chernikov";

    //substrings are SLOW (normally)

    //instead, a string_view just passes around the pointer and size: EFFICIENT

    std::string_view firstName(name.c_str(), 3); //.c_str() casts to const char*
    std::string_view lastName(namechar + 4, 9);
    PrintName(firstName);
    PrintName(lastName);

    std::cout << s_AllocCount << " Allocations\n";

}
