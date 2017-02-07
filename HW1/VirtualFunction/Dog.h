/*******************************************
Name: Omid Azodi
Class: CS542
Date: 02/06/2017
Professor: Dr. Ye
File Name: Dog.h
*******************************************/

#include "Animal.h"

/***************************************************
Description: Dog deriving from parent class Animal

@methods:
Dog()     -> Default Constructor
~Dog()    -> Destructor
void Jump(); -> Print Message based on Dog
void Speak(); -> Override Print Message based on Dog
****************************************************/
class Dog: public Animal
{
public:
	Dog();
	~Dog();
	void Jump();
	void Speak();
};


