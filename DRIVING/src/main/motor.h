#ifndef MOTOR
#define MOTOR

class Motor {
 private:
  int pin;

 public:
  Motor(int);
  void SetSpeed(int);
}
 

#endif
