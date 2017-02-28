#include "AnimalHead.h"
#include <iostream>
using namespace std;

AnimalHead::AnimalHead() :Head()
{
	cout << "Making Animal Head..." << endl;
}

void AnimalHead::action()
{
	cout << "Animal Head is staring" << endl;
}