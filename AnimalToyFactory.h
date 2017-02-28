#ifndef ANIMALTOYFACTORY_H
#define ANIMALTOYFACTORY_H
#include "ToyFactory.h"

class AnimalToyFactory :public ToyFactory
{
	public: 
		AnimalToyFactory();
		Head* makeHead(string name);
		Leg* makeLeg(string name);
		Body* makeBody(string name);
		Arm* makeArm(string name);
};
#endif