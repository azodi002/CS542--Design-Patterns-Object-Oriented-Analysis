#include "RobotLeg.h"
#include <iostream>
using namespace std;

RobotLeg::RobotLeg() :Leg()
{
	cout << "Making Robot Leg..." << endl;
}

void RobotLeg::action()
{
	cout << "Robot Leg WALKS" << endl;
}

