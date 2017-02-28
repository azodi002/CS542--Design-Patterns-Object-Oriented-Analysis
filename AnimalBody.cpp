#include "AnimalBody.h"
#include <iostream>
using namespace std;

AnimalBody::AnimalBody() :Body()
{
	cout << "Making Animal Body..." << endl;
}

void AnimalBody::action()
{
	cout << "Animal Body laying down" << endl;
}
