#include"../motor.h"

void lowerBucket(){
  emmerMotor.SetSpeed(-255);
}

void stopLowerBucket(){
  emmerMotor.SetSpeed(0);
}

