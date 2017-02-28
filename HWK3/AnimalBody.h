#ifndef ANIMALBODY_H
#define ANIMALBODY_H
#include "Body.h"

class AnimalBody :public Body
{
	public:
		AnimalBody();
		void action();
};

#endif