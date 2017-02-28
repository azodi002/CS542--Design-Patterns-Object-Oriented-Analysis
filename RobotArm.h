#ifndef ROBOTARM_H
#define ROBOTARM_H
#include "Arm.h"

class RobotArm : public Arm
{
	public:
		RobotArm();
		void action();
};

#endif