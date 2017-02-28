#include "AnimalArm.h"
#include <iostream>
using namespace std;

AnimalArm::AnimalArm() :Arm()
{
	cout << "Making Animal Arm..." << endl;
}

void AnimalArm::action()
{
	cout << "Animal Arm hugging" << endl;
}
