#include"../motor.h"

void lowerPump(){
  pompMotor.SetSpeed(255);
}

void stopLowerPump(){
  pompMotor.SetSpeed(0);
}
