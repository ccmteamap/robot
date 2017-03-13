#include"motor.h"

Motor::Motor(int pin) : pin(pin) {
  pinMode(pin, OUTPUT);
}

void Motor::SetSpeed(int speed){
  analogWrite(pin, speed % 255);
}
