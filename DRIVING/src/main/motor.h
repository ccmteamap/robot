#ifndef MOTOR_H
#define MOTOR_H

class Motor {
 private:
  int forwardPin;
  int backwardPin;
  int speed;

 public:
  Motor(int, int);
  void SetSpeed(int);
  int GetSpeed();
};
 

#endif
