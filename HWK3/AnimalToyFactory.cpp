#include "AnimalToyFactory.h"

AnimalToyFactory::AnimalToyFactory()
{
	cout << "AnimalToyFactory created" << endl;
}

Head* AnimalToyFactory:: makeHead(string name)
{
	Head* head = NULL;

	if (name == "AnimalHead")
	{
		head = new AnimalHead();
	}
	return head;
}

Leg* AnimalToyFactory::makeLeg(string name)
{
	Leg* leg = NULL;
	
	if (name == "AnimalLeg")
	{
		leg = new AnimalLeg();
	}

	return leg;
}

Body* AnimalToyFactory::makeBody(string name)
{
	Body* body = NULL;
	
	if (name == "AnimalBody")
	{
		body = new AnimalBody();
	}

	return body;
}

Arm* AnimalToyFactory::makeArm(string name)
{
	Arm* arm = NULL;

	if (name == "AnimalArm")
	{
		arm = new AnimalArm();
	}

	return arm;
}