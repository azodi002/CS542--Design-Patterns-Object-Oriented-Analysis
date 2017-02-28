#include "RobotBody.h"
#include <iostream>
using namespace std;

RobotBody::RobotBody() :Body()
{
	cout << "Making Robot Body" << endl;
}

void RobotBody::action()
{
	cout << "Robot Body holds electronics" << endl;
}
