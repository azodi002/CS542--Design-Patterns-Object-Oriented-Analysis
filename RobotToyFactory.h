#ifndef ROBOTTOYFACTORY_H
#define ROBOTTOYFACTORY_H
#include "ToyFactory.h"

class RobotToyFactory :public ToyFactory
{
	public:
		RobotToyFactory();
		Head* makeHead(string name);
		Leg* makeLeg(string name);
		Body* makeBody(string name);
		Arm* makeArm(string name);
};
#endif