#ifndef ROBOTLEG_H
#define ROBOTLEG_H
#include "Leg.h"

class RobotLeg:public Leg
{
	public:
		RobotLeg();
		void action();
};

#endif