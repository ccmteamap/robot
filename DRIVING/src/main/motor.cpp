#include"motor.h"
#include<Arduino.h>

Motor::Motor(int fPin, int bPin) : forwardPin(fPin), backwardPin(bPin) {
  pinMode(fPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

//tussen -255 (achteruit, richting vuur) en 255 (vooruit richting bassin)
void Motor::SetSpeed(int speed){
  if(speed < 0) {
    analogWrite(backwardPin, speed);
    analogWrite(forwardPin, 0);
  }
  else {
    analogWrite(backwardPin, 0);
    analogWrite(forwardPin, speed);
  }
}

int Motor::GetSpeed() {
  return speed;
}
