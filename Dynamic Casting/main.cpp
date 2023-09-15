#include <iostream>

class Entity
{
public:
    virtual void PrintName() {}
};

class Player : public Entity
{
};

class Enemy : public Entity
{
};

int main() {

    //used for classes among the inheritance hierarchy

    Player* player = new Player();
    Entity* e = player;
    Entity* en = new Enemy();

    //similar to reinterpret case: must be used for pointers or references
    //does a run time check: sets to null if impossible to cast
    //a little slower
    //ENABLE Run-Time Type Information (/GR)

    //Requires that base class has at least 1 VIRTUAL method
    Player* p1 = dynamic_cast<Player*>(en);
    if(p1)
    {
        std::cout << "P1 cast worked\n";
    }

    Player* p2 = dynamic_cast<Player*>(e);
    if(p2)
    {
        std::cout << "P2 cast worked\n";
    }


}
