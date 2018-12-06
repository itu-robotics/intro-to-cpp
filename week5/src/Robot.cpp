#include <iostream>
#include <Robot.h>

using namespace std;

Robot::Robot(double _nWheels, double _weight)
{
	m_nWheels = _nWheels;
	m_weight = _weight;
}

Robot::~Robot() {}

void Robot::move(double speed)
{
	cout << "Moving at a speed of " << speed << endl;
}

void Robot::stop()
{
	cout << "Robot stopped" << endl;
}

double Robot::getWeight()
{
	return m_weight;
}

double Robot::getNWheels()
{
	return m_nWheels;
}

void Robot::setWeight(double _weight)
{
	m_weight = _weight;
}

void Robot::setNWheels(double _nWheels)
{
	m_nWheels = _nWheels;
}
