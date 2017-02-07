/*******************************************
Name: Omid Azodi
Class: CS542
Date: 02/06/2017
Professor: Dr. Ye
File Name: Animal.cpp
*******************************************/
#include "Animal.h"

Animal::Animal() 
{ 
	cout << "Constructor ****Animal****" << endl; 
}

Animal::~Animal() 
{ 
	cout << "Deconstructor ****Animal****" << endl; 
}

/**************************************
@method -> void Jump()
@param  -> NONE
@return type = void
Description: Print Base class message
***************************************/
void Animal::Jump() 
{
	cout << "Jumping" << endl; 
}

/**************************************
@method -> void Speak()
@param  -> NONE
@return type = void
Description: Print Base class message
***************************************/
void Animal::Speak() 
{ 
	cout << "Speaking" << endl; 
}
