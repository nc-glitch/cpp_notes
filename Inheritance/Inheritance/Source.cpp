#include <iostream>

class Entity
{
public:
	float X, Y;

	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
};

class Player : public Entity
{
public:
	const char* Name;

	void PrintName()
	{
		std::cout << Name << std::endl;
        X = 5;
	}
};

int main()
{
	Player player;
	player.Move(5, 5);
	player.X = 2;
}