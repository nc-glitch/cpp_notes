//
// Created by Noah on 1/31/2023.
//

#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;
public:
    Entity() : m_Name("Unknown") {}
    Entity(const String& name) : m_Name(name) {}

    const String& GetName() const { return m_Name; }
};

int main()
{
    //stack instantiation
    Entity entity; //auto-calls the default constructor

    //even a pointer to an object in a scope will fail outside of the scope

    //heap allocation
    Entity* e = new Entity("Cherno"); //notice "Entity*" and then "Entity" (no "*" after new)
    delete e;

    std::cin.get();
}

