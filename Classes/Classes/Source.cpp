#include <iostream>


class Player //could be "struct Player" instead: exact same thing but structs are public by default. C also only has structs.
//Don't use inheritance with structs either
//THAT IS IT: public instead of private by default
{
	//int z; private data

public:
	int x, y;
	int speed;

	void Move(int xa, int ya) //same thing as the function outside of this calss
	{
		x += xa * speed;
		y += ya * speed;
	}

};

void Move(Player& player, int xa, int ya)
{
	player.x += xa * player.speed;
	player.y += ya * player.speed;
}

class Log //classes must preceed their use
{
public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;

private:
	int m_LogLevel = LogLevelInfo; //convention "m_" for private member variables
public:
	void SetLevel(int level)
	{
		m_LogLevel = level;
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LogLevelError)
			std::cout << "[ERROR]" << message << std::endl;
	}
	void Warn(const char* message)
	{
		if (m_LogLevel >= LogLevelWarning)
			std::cout << "[WARNING]" << message << std::endl;
	}
	void Info(const char* message)
	{
		if (m_LogLevel >= LogLevelInfo)
			std::cout << "[INFO]" << message << std::endl;
	}
};

struct Entity
{
	static int x, y;

	void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}
};

//MUST define static vars externally
int Entity::x; //data type "scope"::"name";
int Entity::y;

int s_Var = 10;
//or
extern int s_V; //searches for external variable of same name so that it can be used;
//cannot be redefined in this first declaration

//CONSTRUCTORS
//C++ has an automatic basic constuctor, that basically does nothing.
/*side note - if a class is made only for the purpose of static variable :
  you can either hide the constuctor as private or "*class_name*() = delete:"
*/
class Ent
{
public:
	float x, y;
	
	//constuctor function that's similar to python: v
	void Init()
	{
		x = y = 0.0f; //0.0f is slightly better as 0 casts from an int and 0.0 casts from a double
	}
	Ent()
	{
		x = y = 0.0f; //in java, variables are automatically set to 0, not in c++
	}
	Ent(float x, float y)
	{
		this->x = x; this->y = y; //"this->" in c++, instead of "this."
	}

	//DESTRUCTOR right here: "~" + class name
	~Ent()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}

	void Print()
	{
		std::cout << x << ", " << y << std::endl;
		//At first, random values are reproduced because memory was instantiated, but  not INITIALIZED
	}
};

//DESTRUCTORS, deleting objects & cleaning memory. 

void Function()
{
	Ent a; a.Init();
	Ent b(0.5f, 0.3f);
	b.Print();
	//"b.~Ent()" the literal destructor command (normally called automatically)
}

int main()
{
	//Automatically destroys entity when it exits Function() because the program is not executing out of scope
	Function();

	Player player;
	player.x = 5; player.y = 3;
	Move(player, 1, 1); //static version
	player.Move(1, 1); //class-method version
	//can alternatively be constucted like
	Player pl = { 4,2,1 }; //{int x, int y, int speed}


	Log log;
	log.SetLevel(log.LogLevelWarning);
	log.Warn("Hello");

	Entity e1; e1.x = 1; e1.y = 2;
	//cannot write like "Entity e = { 1, 2 };" anymore
	Entity e2; e2.x = 3; e2.y = 4;
	//because the variables are aliases, can be used like this:
	Entity::x = 5; Entity::y = 6;
}

