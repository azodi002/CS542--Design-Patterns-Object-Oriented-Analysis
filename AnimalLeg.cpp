#include "AnimalLeg.h"
#include <iostream>
using namespace std;

AnimalLeg::AnimalLeg() :Leg()
{
	cout << "Making Animal Leg" << endl;
}

void AnimalLeg::action()
{
	cout << "Animal Leg playing" << endl;
}