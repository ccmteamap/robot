#include"motor.h"
#include<Arduino.h>

Motor::Motor(int pin) : pin(pin) {
  pinMode(pin, OUTPUT);
}

void Motor::SetSpeed(int speed){
  analogWrite(pin, speed % 255);
}

int Motor::GetSpeed() {
  return speed;
}
