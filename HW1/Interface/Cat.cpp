/*******************************************
Name: Omid Azodi
Class: CS542
Date: 02/06/2017
Professor: Dr. Ye
File Name: Cat.cpp
*******************************************/
#include "Cat.h"

Cat::Cat()
{ 
	cout << "Creating Cat" << endl; 
}

Cat::~Cat() 
{ 
	cout << "Destroying Cat" << endl; 
}

/**************************************
@method -> void Speak()
@param  -> NONE
@return type = void
Description: Print Cat Message
***************************************/
void Cat:: Speak() 
{ 
	cout << "Meow" << endl; 
}
