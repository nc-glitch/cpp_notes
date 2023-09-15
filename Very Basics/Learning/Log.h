#pragma once //include each bit once per translation unit

//inline copy and pastes and references of the function in the other files
//static  creates its own instance for each file
#ifndef _LOG_H //basically the same thing as pragma once, but longer
#define _LOG_H
inline void Log(const char* message) {
	std::cout << message << std::endl; 
}
#endif

//header files are just files we copy and paste into other files
//for simplicity
//use the #include"file name.h"
//Quotes are for everything, convention is for file "relative" to the current
//Angular brackets search for a folder of directories
//C-file have the .h ending, while c++ ones do not