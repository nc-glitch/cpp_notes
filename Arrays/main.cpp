#include <iostream>
#include <array>

class Entity
{
public:
    int* example = new int[5];

    Entity()
    {
        for(int i = 0; i < 5; i++) example[i] = 2;
    }
};

int main()
{
    int example[5]; //array of 5 integers stacked
    example[0]; //just like Java

    //example[5] --> memory access violation: writes into memory that isn't ours (only detected in debug mode)
    for(int i = 0; i < 5; i++)
       example[i] = i + 1;

    int* ptr = example;
    *(ptr + 2) = 6; //same thing as "example[2]"
    *(int*)((char*)ptr + 8) = 6; //same thing as above
    //increments by 8 because each char is 1 byte, while integers are 4

    //ARRAY SIZE FOR STACK
    int Literal_Size = sizeof(example); int Length = Literal_Size / sizeof(int);


    //HEAP
    int* another = new int[5];
    delete[] another; //SQUARE BRACKETS FOR DELETE

    Entity e; //now at the memory address there is just another pointer to the actual data stored in the memory
    //NO EASY WAY TO FIND ARRAY SIZE OF HEAP: maintain yourself as const int size;


    //C++ STANDARD ARRAY
    std::array<int, 5> standard; //slight overhead
    standard.size(); //this exists though!

    std::cin.get();
}
