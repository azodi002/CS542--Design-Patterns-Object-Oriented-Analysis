/*******************************************
Name: Omid Azodi
Class: CS542
Date: 02/06/2017
Professor: Dr. Ye
File Name: Animal.h
*******************************************/
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

/**********************************
Description: Animal class is Parent class
Subclass: Dog & Cat

@methods:
Animal()     -> Default Constructor
~Animal()    -> Destructor
void Jump(); -> Print Message
virtual void Speak(); -> Print Message based on class
***********************************/

class Animal
{
public:
	Animal();
	~Animal();
	void Jump();
	virtual void Speak();
};

#endif
