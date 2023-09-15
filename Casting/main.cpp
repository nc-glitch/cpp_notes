#include <iostream>
#include <string>

class Base {
public:
    Base() {}
    ~Base() {}
};

class Derived : public Base {
public:
    std::string yes = "YES";
    Derived() {}
    ~Derived() {}

    void Print() { std::cout << yes << std::endl; }
};

class AnotherClass : public Base {
public:
    AnotherClass() {}
    ~AnotherClass() {}
};

int main() {

    //implicit conversion between the basic c++ data types

    //typical casts: (cast_type)

    double value = 5.25;

    //C++ STYLE CASTS

    //They don't do anything that C style casts can't do, but they improve syntax and add compile-time checking
    double s = static_cast<int>(value) + 5.3;

    //used for casting pointers to other pointer types: no actual memory conversion occurs
    int* ptrcast = reinterpret_cast<int*>(&value);

    std::cout << *ptrcast << std::endl;

    Derived* derived = new Derived();
    derived->Print();

    Base* base = derived;

    //CHECKS if the cast works, otherwise CASTS TO NULL
    AnotherClass* ac = dynamic_cast<AnotherClass*>(base);

    Base* truebase = new Base();
    //REMINDER-DOESN"T WORK: base->Print();
    //Can't call child class methods for a base class that are polymorphic

    //can re-cast it though, to use child class methods
    reinterpret_cast<Derived*>(base)->Print();

    //CONST CAT ALSO EXISTS

    //CAN'T CAST FROM BASE TO CHILD THOUGH UNLESS IT WAS ALREADY A POLYMORPH OF THE CHILD
    //reinterpret_cast<Derived*>(truebase)->Print();

}
