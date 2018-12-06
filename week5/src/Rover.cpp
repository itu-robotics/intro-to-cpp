#include <iostream>
#include <Rover.h>
using namespace std;

Rover::Rover(double _nWheels, double _weight) : Robot::Robot(_nWheels, _weight) {
	m_nWheels = _nWheels;
	m_weight = _weight;
}

Rover::~Rover() { }

void Rover::moveArm()
{
	cout << "Moving arm " << robotArm << endl;
}

