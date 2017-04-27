#include"motor.h"
#include<Arduino.h>
#include"pin.h"

Motor mainMotor(MAIN_MOTOR_FORWARDS_PIN, MAIN_MOTOR_BACKWARDS_PIN);
Motor emmerMotor(EMMER_MOTOR_FORWARDS_PIN, EMMER_MOTOR_BACKWARDS_PIN);
Motor pompMotor(POMP_MOTOR_FORWARDS_PIN, POMP_MOTOR_BACKWARDS_PIN);

Motor::Motor(int fPin, int bPin) : forwardPin(fPin), backwardPin(bPin) {
  pinMode(fPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  speed = 0;
  power = 100;

  //Serial.println(&speed);
  //Serial.println(&power);
}

//tussen -255 (achteruit, richting vuur) en 255 (vooruit richting bassin)
void Motor::SetSpeed(int newSpeed){
  if(newSpeed == GetSpeed()){
    return;
  }
  
  speed = newSpeed;
  outputToMotor();
}

int Motor::GetSpeed() {
  return speed;
}

void Motor::SetPower(unsigned int newPower) {
  if(newPower == GetPower()){
    return;
  }

  power = newPower % 101;

  Serial.print("Changing power: ");
  Serial.println(power);
  
  outputToMotor();
}

unsigned int Motor::GetPower() {
  return power;
}

void Motor::outputToMotor(){
  int outSpeed = mapSpeed();
  
  if(outSpeed < 0) {
    Serial.println(outSpeed);
    analogWrite(backwardPin, outSpeed * -1);
    analogWrite(forwardPin, 0);
  }
  else {
    Serial.println(outSpeed);
    analogWrite(backwardPin, 0);
    analogWrite(forwardPin, outSpeed);
  }
}

int Motor::mapSpeed(){
  return (speed * power) / 100;
}

