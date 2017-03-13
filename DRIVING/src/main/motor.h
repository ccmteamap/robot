#ifndef MOTOR
#define MOTOR

class Motor {
 private:
  int pin;
  int speed;

 public:
  Motor(int);
  void SetSpeed(int);
  int GetSpeed();
};
 

#endif
