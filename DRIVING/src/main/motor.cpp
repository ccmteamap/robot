#include"motor.h"
#include<Arduino.h>

Motor::Motor(int fPin, int bPin) : forwardPin(fPin), backwardPin(bPin) {
  pinMode(fPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

//tussen -255 (achteruit, richting vuur) en 255 (vooruit richting bassin)
void Motor::SetSpeed(int newSpeed){
  if(newSpeed < 0) {
    analogWrite(backwardPin, newSpeed);
    analogWrite(forwardPin, 0);
  }
  else {
    analogWrite(backwardPin, 0);
    analogWrite(forwardPin, newSpeed);
  }

  speed = newSpeed;
}

int Motor::GetSpeed() {
  return speed;
}
