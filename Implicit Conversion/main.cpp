 #include <iostream>

class Entity
{
    std::string m_Name;
    int m_Age;
public:
    explicit Entity(const std::string& name)
    : m_Name(name), m_Age(-1) {}
    Entity(int age)
    : m_Name("Unknown"), m_Age(age) {}

};

void PrintEntity(const Entity& entity)
{
}

int main() {
    Entity a("Cherno");

    //Implicitly constructing objects through the constructor
    Entity b = 22;
    PrintEntity(18);

    //no longer works wit explicit keyword
    PrintEntity(std::string("Chern"));


    return 0;
}
