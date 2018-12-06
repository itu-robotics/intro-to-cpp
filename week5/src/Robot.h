#ifndef ROBOT_H_
#define ROBOT_H_

class Robot
{

private:
  double m_nWheels;
  double m_weight;

public:
  Robot(double x,double y);
  virtual ~Robot();
  void move(double speed);
  void stop();
  double getWeight();
  double getNWheels();
  void setWeight(double _weight);
  void setNWheels(double _nWheels);
  double size[3];

};

#endif /* ROBOT_H_ */
