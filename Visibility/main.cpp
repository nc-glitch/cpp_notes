#include <iostream>
#include <string>


//3 basic: private, public, and protected

class Entity{
private:
    int X;
protected:
    int Y;
public:
    int Z;
public:
    Entity() : X{0} {}
    void Print()
    {
        std::cout<<X<<std::endl;
    }
};

class Player : public Entity
{
public:
    Player() : Entity() {
        Y = 0; //cannot declare like base class because it does not have
    }
};

int main()
{
    Entity e;
    e.Print();
    e.Z = 2; //public data
}
