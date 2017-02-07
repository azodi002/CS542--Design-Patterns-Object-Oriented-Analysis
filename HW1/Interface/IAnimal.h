/**********************
Name: Omid Azodi
Professor: Dr. Ye
Class: CS542
Date: 02/06/2017
File Name: IAnimal.h
**********************/
#ifndef IANIMAL_H
#define IANIMAL_H

#include <iostream>
using namespace std;
/*****************************************
Description:
IAnimal is interface for Dog & Cat class
Pure virtual function Speak()
******************************************/
class IAnimal
{
public:
	virtual void Speak() = 0;
};

#endif