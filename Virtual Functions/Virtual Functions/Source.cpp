#include <iostream>
#include <string>

class Entity
{
public:
    virtual std::string GetName() {return "Entity"; }

};

class Player : public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string& name) : m_Name(name) {}

    std::string GetName() override { return m_Name; }
};




//MODIFIED FOR THE PURE VIRTUAL FUNCTIONS
class Printable
{
public:
    virtual std::string GetClassName() = 0;
};

class Ent : public Printable
{
public:
    virtual std::string GetName() = 0; //declaring the pure virtual function

    std::string GetClassName() override { return "Ent"; }
};

class Play : public Ent // for multiple inheritance, add a ", *Class Name*
{
private:
    std::string m_Name;
public:
    Play(const std::string& name)
        : m_Name(name) {}

    std::string GetName() override { return m_Name; }
};

void Print(Printable* obj)
{
    std::cout << obj->GetClassName() << std::endl;
}

int main()
{
    Entity* e = new Entity();
    std::cout << e->GetName() << std::endl;

    Player* p = new Player("Cherno");
    std::cout << p->GetName() << std::endl;

    //attempting polymorphism
    Entity* entity = p;
    std::cout << entity->GetName() << std::endl;
    //return "Entity"? Returns Entity-method instead of the Player-method
    //automatically calls the type belonging to the declaration

    //--> VIRTUAL FUNCTIONS USE CASE
    //*adds virtual to GetName() function
    //can also add "override" to the overwriting-methods: helpful convention
    //performance losses: implementing and using a v-table for each method every time (very minimal though)

    //Basically "virtual" functions allow a function to be OVERRIDEN IN CHILD CLASSES USING POLYMORPHISM
    //use "virtual" and "override"


    //PURE VIRTUAL FUNCTIONS (INTERFACES)
    Ent* ent = new Play("Cherno"); //cannot instantiate the abstract class, can have polymorphism though

    std::cin.get();
}
