#include <iostream>
#define INTEGER int
using namespace std;


void log(const char* s);

//class variable can be simply declared, not sure about accessibility though
int ab;


#if 1 //if 0 = false: ignores the section inbetween as if it didn't exist
int main() //special function that doesn't need a return val
{
    ab = 6;
    bool comparisonResult = ab == 6;
    //can right click in debugger and select disassembly to inspect assembly language
    if (comparisonResult) {
        log("hello world");
    }
    const char* ptr = nullptr;
    if (ptr)
        log(ptr);
    else
        log("Pointer is null!");

    //cin.get();
    
    //ctrl + f7 = compile file
    //ctrl + b = build window
    //ctrl + shift + b = build solution
    INTEGER c = 3; c++; std::cout << c << std::endl;
    //ints range from about -2 bil --> +2 bil: 4 bytes
    //autocasts if one number is a double
    //long alt for 8 bytes
    unsigned int b = 4294967295;
    char a = 65; //works as well according to ASCII
    cout << b << endl;
    //decimals: float, double, long double
    
    //boolean are called using "bool" 
    //bool and ints have the same data size because smallest allcoation is 1 byte
    cout << sizeof(bool) << endl; //# of bytes allocated

    //pointer: bool*
    //refr: bool&

    cout << ab << endl;
    
    int i = 0; bool condition = true;
    for (; condition;)
    {
        i++;
        if (!(i < 5)) condition = false;
    }

    //while loops still exist
    //do while loops are the exact same except they run without checking the first time

    //CONTROL FLOW
    //continue; --> goes to next iteration of loop (basically skips all the remaining code in the loop)
    //break; exit loop
    //return *value*; leaves function


#include "EndBrace.h"
    

//FUNCTIONS : diff between methods is that functions are not part of a class
//accessibilty: none, private, protected?; type: none, static, inline; return type; name; (paramaters)
//call a function by just typing it as appropriate based off of output (like Java)
    
