#include "RobotToyFactory.h"

RobotToyFactory::RobotToyFactory()
{
	cout << "RobotToyFactory created..." << endl;
}

Head* RobotToyFactory::makeHead(string name)
{
	Head* head = NULL;
	if (name == "RobotHead")
	{
		head = new RobotHead();
	}
	return head;
}

Leg* RobotToyFactory::makeLeg(string name)
{
	Leg* leg = NULL;
	if (name == "RobotLeg")
	{
		leg = new RobotLeg();
	}

	return leg;
}

Body* RobotToyFactory:: makeBody(string name)
{
	Body* body = NULL;
	if (name == "RobotBody")
	{
		body = new RobotBody();
	}

	return body;
}

Arm* RobotToyFactory::makeArm(string name)
{
	Arm* arm = NULL;
	if (name == "RobotArm")
	{
		arm = new RobotArm();
	}

	return arm;
}