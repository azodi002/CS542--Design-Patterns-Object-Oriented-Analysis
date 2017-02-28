#include "RobotArm.h"
#include <iostream>
using namespace std;

RobotArm::RobotArm() :Arm()
{
	cout << "Making Robot ARM" << endl;
}

void RobotArm::action()
{
	cout << "Robot Arm PUNCHES" << endl;
}
