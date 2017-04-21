#include"motor.h"
#include<Arduino.h>

Motor mainMotor(3, 5);
Motor emmerMotor(6, 9);
Motor pompMotor(10, 11);

Motor::Motor(int fPin, int bPin) : forwardPin(fPin), backwardPin(bPin) {
  pinMode(fPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  this->power=100;
}

//tussen -255 (achteruit, richting vuur) en 255 (vooruit richting bassin)
void Motor::SetSpeed(int newSpeed){
  speed = newSpeed;
  outputToMotor();
}

int Motor::GetSpeed() {
  return speed;
}

void Motor::SetPower(unsigned int newPower) {
	power = newPower % 101;
  outputToMotor();
}

unsigned int Motor::GetPower() {
	return power;
}

void Motor::outputToMotor(){
  int outSpeed = mapSpeed();
  
  if(outSpeed < 0) {
    analogWrite(backwardPin, outSpeed);
    analogWrite(forwardPin, 0);
  }
  else {
    analogWrite(backwardPin, 0);
    analogWrite(forwardPin, outSpeed);
  }
}

int Motor::mapSpeed(){
  return (speed * power) / 100;
}

