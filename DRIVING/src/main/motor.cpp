#include"motor.h"
#include<Arduino.h>

Motor mainMotor(5, 6);

Motor::Motor(int fPin, int bPin) : forwardPin(fPin), backwardPin(bPin) {
  pinMode(fPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  this->maxSpeed=255;
}

//tussen -255 (achteruit, richting vuur) en 255 (vooruit richting bassin)
void Motor::SetSpeed(int newSpeed){
  int mappedSpeed = (newSpeed * power) / 100;
  
  if(newSpeed < 0) {
    analogWrite(backwardPin, mappedSpeed);
    analogWrite(forwardPin, 0);
  }
  else {
    analogWrite(backwardPin, 0);
    analogWrite(forwardPin, mappedSpeed);
  }

  speed = newSpeed;
}

int Motor::GetSpeed() {
  return speed;
}

void Motor::SetPower(unsigned int newPower) {
	power = newPower % 101;

	speed = (speed * power) / 100;
}

unsigned int Motor::GetPower() {
	return power;
}

