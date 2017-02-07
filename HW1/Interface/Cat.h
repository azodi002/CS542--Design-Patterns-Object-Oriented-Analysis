/*******************************************
Name: Omid Azodi
Class: CS542
Date: 02/06/2017
Professor: Dr. Ye
File Name: Cat.h
*******************************************/
#include "IAnimal.h"

/***************************************************
Description: Cat deriving from parent class IAnimal

@methods:
Cat()     -> Default Constructor
~Cat()    -> Destructor
void Speak(); -> Override Print Message based on Cat
****************************************************/
class Cat : public IAnimal
{
public:
	Cat();
	~Cat();
    void Speak();
};