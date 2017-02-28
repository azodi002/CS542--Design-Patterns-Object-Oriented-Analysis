#ifndef TOYFACTORY_H
#define TOYFACTORY_H

#include "RobotArm.h"
#include "RobotBody.h"
#include "RobotHead.h"
#include "RobotLeg.h"

#include "AnimalArm.h"
#include "AnimalBody.h"
#include "AnimalHead.h"
#include "AnimalLeg.h"

#include <iostream>
using namespace std;

class ToyFactory
{
	public:
		virtual Head* makeHead(string name) = 0;
		virtual Leg* makeLeg(string name) = 0;
		virtual Body* makeBody(string name) = 0;
		virtual Arm* makeArm(string name) = 0;
};
#endif