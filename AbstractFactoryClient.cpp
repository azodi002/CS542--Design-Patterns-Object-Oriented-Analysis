#include "AnimalToyFactory.h"
#include "RobotToyFactory.h"

template<typename T>
void printActionStatements(T* functionPart[])
{
	for (int i = 0; i < 2; i++)
	{
		functionPart[i]->action();
	}
}

int main(int argc, char* argv[])
{
	AnimalToyFactory animalToyFactory;
	RobotToyFactory robotToyFactory;

	Head* head[2];
	head[0] = animalToyFactory.makeHead("AnimalHead");
	head[1] = robotToyFactory.makeHead("RobotHead");
	cout << endl << "*************ACTIONS FOR HEAD****************" << endl;
	printActionStatements(head);
	cout  << "*************ACTIONS FOR HEAD****************" << endl << endl;

	Arm* arm[2];
	arm[0] = animalToyFactory.makeArm("AnimalArm");
	arm[1] = robotToyFactory.makeArm("RobotArm");

	cout << endl << "*************ACTIONS FOR ARM****************" << endl;
	printActionStatements(arm);
	cout << "*************ACTIONS FOR ARM****************" << endl << endl;

	Body* body[2];
	body[0] = animalToyFactory.makeBody("AnimalBody");
	body[1] = robotToyFactory.makeBody("RobotBody");
	cout << endl << "*************ACTIONS FOR BODY****************" << endl;
	printActionStatements(body);
	cout << "*************ACTIONS FOR BODY****************" << endl << endl;

	Leg* leg[2];
	leg[0] = animalToyFactory.makeLeg("AnimalLeg");
	leg[1] = robotToyFactory.makeLeg("RobotLeg");
	cout << endl << "*************ACTIONS FOR LEG****************" << endl;
	printActionStatements(leg);
	cout << "*************ACTIONS FOR LEG****************" << endl << endl;

	while (true);

	return 0;
}
