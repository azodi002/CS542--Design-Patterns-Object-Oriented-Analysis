/*******************************************
Name: Omid Azodi
Class: CS542
Date: 02/06/2017
Professor: Dr. Ye
File Name: AnimalClient.cpp
*******************************************/
#include "Cat.h"
#include "Dog.h"

//animalID enumeration used for index of static array of Animal Pointers
enum animalID { firstAnimal, secondAnimal, thirdAnimal };

int main(int argc, char* argv[])
{
	const int MAX_ANIMAL = 3;

	//Array of size 3, consisting of Animal*
	Animal* animalList[MAX_ANIMAL];
	animalList[firstAnimal] = new Dog;
	animalList[secondAnimal] = new Cat;
	animalList[thirdAnimal] = new Dog;
	
	//Go through each element in Animal* array and call Speak & Jump methods 
	for (int animalIterator = 0; animalIterator < MAX_ANIMAL; ++animalIterator) 
	{
	    cout << endl;
		animalList[animalIterator]->Speak();
		animalList[animalIterator]->Jump();
	}

	return 0;
}
