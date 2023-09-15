#include <iostream>

class Base
{
public:
    int x;
    Base() { std::cout << "Base Constructor\n"; }

    //virtual tells the compiler to look for any other overloaded methods that may be inherited
    //calls both destructor methods though with this case of virtual
    virtual ~Base() { std::cout << "Base Destructor\n"; }
};

//must be public for base to access;
class Derived : public Base{
public:
    Derived() {
        std::cout << "Derived Constructor\n";
        Base::x = 3;
    }
    ~Derived() { std::cout << "Derived Destructor\n"; }
};

int main() {

    //series of subclasses
    //class b is derived from a
    //want to reference b as a (polymorphism)
    //THEN: u want the VIRTUAL DESTRUCTOR of b to run, not a

    Base* base = new Base();
    delete base; std::cout << std::endl;

    Derived* derived = new Derived();
    delete derived; std::cout << std::endl;

    //by defuault only calls base destructor, not derived, leading to a memory leak
    Base* poly = new Derived();
    delete poly;

}
