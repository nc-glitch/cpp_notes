#include <iostream>

class Entity
{
    int d = 0;

    //can still be changed in const methods
    mutable int m = 10;

    //must use pointer second time, else it will be a normal variable
    int* e, *f;
public:
    //const after method name means it cannot modify any object data (a "read only" method)
    int getD() const {
        m = 12;
        return d;
    }

    //can have a nonconst method for nonconst objects
    int getD() { return d; }
};


int main() {
    std::cout << "Hello, World!" << std::endl;

    //variables you shouldn't change, although it's technically possible;
    const int MAX_AGE = 18;
    int* a = new int;
    *a = 2;
    std::cout << *a << std::endl;

    //bypassing const using pointers to edit
    a = (int*)&MAX_AGE;
    std::cout << *a << std::endl; //18
    (*a)++;
    std::cout << *a << std::endl; //19

    //can re-assign value pointed to, but not the pointer itself
    int* const b = new int;

    //const int* == int const*

    //or...
    const int* const c = new int(5);
}
