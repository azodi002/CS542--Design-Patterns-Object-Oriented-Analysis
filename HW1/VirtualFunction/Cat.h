/*******************************************
Name: Omid Azodi
Class: CS542
Date: 02/06/2017
Professor: Dr. Ye
File Name: Cat.h
*******************************************/
#include "Animal.h"

/***************************************************
Description: Cat deriving from parent class Animal

@methods:
Cat()     -> Default Constructor
~Cat()    -> Destructor
void Jump(); -> Print Message based on Cat
void Speak(); -> Override Print Message based on Cat
****************************************************/
class Cat : public Animal
{
public:
	Cat();
	~Cat();
	void Jump();
	void Speak();
};
