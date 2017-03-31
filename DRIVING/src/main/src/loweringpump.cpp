#include"../motor.h"

void lowerPump(){
  extern Motor pompMotor;
  pompMotor.SetSpeed(255);
}

void stopLowerPump(){
  extern Motor pompMotor;
  pompMotor.SetSpeed(0);
}
