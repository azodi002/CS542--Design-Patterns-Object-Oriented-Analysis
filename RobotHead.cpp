#include "RobotHead.h"
#include <iostream>
using namespace std;

RobotHead::RobotHead() :Head()
{
	cout << "Making Robot Head..." << endl;
}

void RobotHead::action()
{
	cout << "Robot Head can Turn" << endl;
}