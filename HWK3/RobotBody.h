#ifndef ROBOTBODY_H
#define ROBOTBODY_H
#include "Body.h"

class RobotBody :public Body
{
	public:
		RobotBody();
		void action();
};

#endif