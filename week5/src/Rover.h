#ifndef ROVER_H_
#define ROVER_H_

#include <Robot.h>

class Rover : public Robot{

private:
	double m_nWheels;
	double m_weight;

public:
	Rover(double _nWheels, double _weight);
	virtual ~Rover();
	void moveArm();

	int robotArm = 0;
};

#endif /* ROVER_H_ */
