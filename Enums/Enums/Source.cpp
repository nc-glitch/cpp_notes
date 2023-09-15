#include<iostream>

int a = 0, b = 2, c = 4;
//not grouped at all
//want to define a type that can only be one of these through
enum Example
{
	A, B, C //default value of ints are 0
};

int main()
{
	Example value = A;
	std::cout << value << std::endl;
	//enums: ways to name values, enhanced integers
}