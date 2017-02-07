/*******************************************
Name: Omid Azodi
Class: CS542
Date: 02/06/2017
Professor: Dr. Ye
File Name: Dog.h
*******************************************/
#include "IAnimal.h"

/***************************************************
Description: Dog deriving from parent class IAnimal

@methods:
Dog()     -> Default Constructor
~Dog()    -> Destructor
void Speak(); -> Override Print Message based on Dog
****************************************************/
class Dog:public IAnimal
{
public:
	Dog();
	~Dog();
	void Speak();
};


