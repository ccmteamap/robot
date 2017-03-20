#ifndef MOTOR_H
#define MOTOR_H

class Motor {
 private:
  int forwardPin;
  int backwardPin;
  int speed;
  unsigned int maxSpeed; //max speed between 0 and 100

 public:
  Motor(int, int);
  void SetSpeed(int);
  int GetSpeed();
  void SetMaxSpeed(unsigned int);
  unsigned int GetMaxSpeed();
};

extern Motor mainMotor;

#endif
