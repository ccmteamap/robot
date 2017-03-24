#ifndef MOTOR_H
#define MOTOR_H

class Motor {
 private:
  int forwardPin;
  int backwardPin;
  int speed;
  unsigned int power; //power between 0 and 100
  void outputToMotor();
  int mapSpeed();

 public:
  Motor(int, int);
  void SetSpeed(int);
  int GetSpeed();
  void SetPower(unsigned int);
  unsigned int GetPower();
};

extern Motor mainMotor;

#endif
