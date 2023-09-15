#include <iostream>
#include <string>

class Entity
{
public:
    int x;
    void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr
{
private:
    Entity* m_Obj;
public:
    ScopedPtr(Entity* entity)
    : m_Obj(entity)
    {
    }

    ~ScopedPtr(){ delete m_Obj; }

    const Entity* operator->()
    {
        return m_Obj;
    }

    Entity* operator->() const
    {
        return m_Obj;
    }
};

struct Vector3
{
    float x, y, z;
};

int main()
{
    Entity e;
    e.Print();

    ScopedPtr Ptr(&e);

    Ptr->Print();

    //sets the objects pointer as base to compare against its data's pointers
    size_t offset = (size_t) &((Vector3*)nullptr)->x;
    //size_t is a more appropriate number type than long long

    std::cout << offset;
}